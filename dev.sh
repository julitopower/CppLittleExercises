#!/bin/bash
ROOT="$( cd "$(dirname "$0")" ; pwd -P)"
WD="/opt/src"

docker run -it --rm -v $ROOT:$WD -w $WD julitopower/dockercppdevemacsclang:gcc9 /bin/bash
