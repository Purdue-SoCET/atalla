# Setup Guidelines 

This document should list any and all required steps to get yourselves setup to run Atalla. Specific setup scripts (like for the PyTorch infrastructure, or PPCI infrastructure) will be defined in sub-team homepages. 

## Basics 

#### SSH into asicfab

The preferred IDE by the AI-HW team is VSCode. Please follow the instructions in [DigitalOcean's tutorial](https://www.digitalocean.com/community/tutorials/how-to-configure-ssh-key-based-authentication-on-a-linux-server#step-2-copying-an-ssh-public-key-to-your-server) on connecting to a remote server. 

You will need to download [Cisco AnyConnect VPN](https://it.purdue.edu/newsroom/2020/200316-webvpn.php) if you plan to SSH from an out-of-campus location.

#### Setup asicfab 

* Run `source /package/asicfab/AccountSetup/init.bash`
* Add the following into `~/.bashrc`
```bash
[[ $- == *i* ]] || return
HOSTNAME=$(hostname)

if [ ${HOSTNAME} == "asicfab.ecn.purdue.edu" ]; then
        source /package/asicfab/AccountSetup/init.bash

        alias ls="ls --color"
        alias ll="ls -la"


        export COPYBUFFER=/package/asicfab/CopyBuffer
        export MODULEPATH=/package/asicfab/AccountSetup/modulefiles:$MODULEPATH
        export PATH=$HOME/.local/bin:$PATH # for python packages
        unset PYTHONPATH
        # For fusesoc + Questa usage
        export MODEL_TECH="$(dirname $(which vsim))"

        ###### CUSTOM CHANGES BELOW THIS LINE #######
        module load gcc/11.2.0 python3/3.11
        module load riscv-gcc verilator/5.036 gtkwave
        module load cadence/xcelium/23.03 siemens/questa/2021.4 intel/quartus-std
        module load lcov
elif [ ${HOSTNAME} == "asicfabu.ecn.purdue.edu" ]; then
        module load verilator gtkwave surfer lcov
else
        echo "Unknown host ${HOSTNAME}; not loading modules"
fi

module load cadence/genus       # used for synthesis
module load cadence/innovus     # used for physical implementation 
module load cadence/virtuoso    # used for manually inspecting and manipulating the design
module load cadence/ssv         # good general module
module load cadence/ddi         # good general module

export LD_PRELOAD=/lib64/libz.so.1
```

#### Setup Github SSH 

Follow the steps in the [Github SSH-ing](https://docs.github.com/en/authentication/connecting-to-github-with-ssh) document. You should be able to clone the Atalla repository locally using `git clone git@github.com:Purdue-SoCET/atalla.git` now.


To test out a basic file, run 
```
git checkout scratchpad_main
make run FILE=./scripts/common/xbar/clos/test.tcl
```