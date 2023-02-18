#!/bin/zsh
# cd ...webForth; scripts/forth_2012.sh
wget "https://github.com/gerryjackson/forth2012-test-suite/archive/refs/heads/master.zip"
unzip master.zip
rm master.zip
cd forth2012-test-suite-master/src
echo "type: INCLUDE ../../scripts/forth2012_runtests.fth" when forth is loaded
node ../scripts/forth_2012.js

# cd ..; rm -r forth2012-test-suite-master

