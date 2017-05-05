#!/bin/bash

# Torque standard installation and setup

# Read PC name
pcname=$(cat /etc/hostname)
echo Enter PC name [$pcname]: 
read tmpname
if [ "$tmpname" ]; then 
  pcname=$tmpname
fi
echo $pcname

# Read number of CPU cores
declare -i ncpus=0
while [ $ncpus -lt 1 ]
do
  ncpus=$(nproc)
  echo Enter number of CPU cores [$ncpus] "(Including HT)": 
  read tmpcpu
  if [ ! "$tmpcpu" ]; then
    tmpcpu=$ncpus
  fi
  if [ ! $(echo "$tmpcpu"|grep -v "[^0-9]") ]; then tmpcpu=0; fi
  if [ "$tmpcpu" ]; then 
    ncpus=$tmpcpu
  fi
  if [ $ncpus -lt 1 ]; then
    echo number of CPU cores must be greater than 0
  fi
done
echo $ncpus

# Read number of maximum running processes
declare -i nrun=0
while [ $nrun -lt 1 -o $nrun -gt $ncpus ]
do
  nrun=$(( ncpus - 1 ))
  echo Enter maximum number of running processes [$nrun] "(Should be smaller than" $ncpus"):" 
  read tmpnode
  if [ ! "$tmpnode" ]; then
    tmpnode=$nrun
  fi
  if [ ! $(echo "$tmpnode"|grep -v "[^0-9]") ]; then tmpnode=0; fi
  if [ "$tmpnode" ]; then 
    nrun=$tmpnode
  fi
  if [ $nrun -lt 1 ]; then
    echo maximum number of running processes must be greater than 0
  fi
  if [ $nrun -gt $ncpus ]; then
    echo maximum number of running processes must be smaller than "/" equal to $ncpus
  fi
done
echo $nrun

# Edit /etc/hosts
echo ' In /etc/hosts change the line: '
echo -e " 127.0.1.1 \t $pcname "
echo ' to '
echo -e " 127.0.0.1 \t $pcname "
echo ' Press any key to continue '
read empty
nano /etc/hosts

# Install Torque from repository
apt-get -y install torque-common torque-server torque-client torque-scheduler torque-mom torque-pam

# Stop PBS server etc.
qterm
killall pbs_sched
killall pbs_mom
killall pbs_server

# Configs
echo $pcname > /var/spool/torque/server_name
echo "SERVERHOST localhost" > /var/spool/torque/torque.cfg

# Setup database
pbs_server -t create

# Setup nodes
echo "$pcname np=$ncpus" > /var/spool/torque/server_priv/nodes
echo "pbs_server = 127.0.0.1" > /var/spool/torque/mom_priv/config

# Create batch queue and set server settings
qmgr $pcname -c 'create queue batch'
qmgr $pcname -c 'set queue batch queue_type = Execution'
qmgr $pcname -c "set queue batch max_running = $nrun"
qmgr $pcname -c "set queue batch resources_max.ncpus = $ncpus"
qmgr $pcname -c "set queue batch resources_max.nodes = 1"
qmgr $pcname -c "set queue batch resources_default.ncpus = 1"
qmgr $pcname -c "set queue batch resources_default.neednodes = 1:ppn=1"
qmgr $pcname -c "set queue batch resources_default.walltime = 24:00:00"
qmgr $pcname -c "set queue batch max_user_run = $nrun"
qmgr $pcname -c "set queue batch enabled = True"
qmgr $pcname -c "set queue batch started = True"
qmgr $pcname -c "set server default_queue = batch"
qmgr $pcname -c "set server scheduling = True"
qmgr $pcname -c "set server query_other_jobs = True"
qmgr $pcname -c "set server submit_hosts = localhost"

# Restart PBS server, scheduler and node server
qterm
pbs_server
pbs_sched
pbs_mom

# Check that the nodes are up
echo "Check that the nodes are up (pbsnodes -a):"
echo "Waiting 5 seconds ..."
sleep 5
pbsnodes -a

# Exit the root terminal and as a normal user test the queue
echo "Exit the root terminal and as a normal user test the queue with the following commands:"
echo "qstat -q"
echo -e "echo \"sleep 30\" | qsub"
echo "qstat"
