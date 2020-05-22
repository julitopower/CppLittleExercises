#!/bin/bash
ROOT="$( cd "$(dirname "$0")" ; pwd -P)"

docker run -it --rm -v $ROOT:/opt/src julitopower/dockerclang9emacs25 /bin/bash
