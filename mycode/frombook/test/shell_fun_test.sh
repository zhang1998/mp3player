#!/bin/bash
# version
function st_op(){
  # stop  the command
  echo "Stop"
}

function start(){
  # Start  the command
  echo "start"
  st_op
}
function start1(){
echo "restart"
}
cmd=$1
${cmd:-start}
