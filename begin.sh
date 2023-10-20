#the path avr-gcc and friends will be extracted to
EXTRACT_PATH=/tmp/sim_tools

rm -rf $EXTRACT_PATH
mkdir $EXTRACT_PATH

#extract to there
xz res -d -c | tar -xzf - -C $EXTRACT_PATH

#set the dll path TODO change to /tmp/sim_tools later
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

export LD_LIBRARY_PATH=$SCRIPT_DIR/result/lib:.
