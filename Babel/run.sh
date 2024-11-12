#!/bin/bash
# Specify folder where you can find sources , on your local machine

SOURCE_FOLDER=/home/alexg/tek3/OOP/latest_16_09_20/CPP_babel_2020/

# Specify destination folder to mount your project into docker                                                                              
DEST_FOLDER=/babel

docker run --rm -v "$SOURCE_FOLDER:$DEST_FOLDER" -it epitechcontent/epitest-docker /bin/bash -c 'useradd student && su - student'
