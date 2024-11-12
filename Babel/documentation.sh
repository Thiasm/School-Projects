#!/bin/bash

mkdir documentation
cp -r diagram/ documentation/image
doxygen Doxyfile
mv html/ documentation/
