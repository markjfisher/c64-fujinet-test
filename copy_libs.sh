#!/bin/bash

ROOT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

rm -rf ${ROOT_DIR}/_libs
mkdir ${ROOT_DIR}/_libs
ZIP_FILE=/d/dev/atari/fujinet/fujinet-lib/dist/fujinet-lib-c64-4.2.0.zip

if [ ! -f ${ZIP_FILE} ]; then
  echo "Couldn't find $ZIP_FILE"
  exit 1
fi

cp ${ZIP_FILE} ${ROOT_DIR}/_libs
unzip ${ZIP_FILE} -d ${ROOT_DIR}/_libs/4.2.0-c64
