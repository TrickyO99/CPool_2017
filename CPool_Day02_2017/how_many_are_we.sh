#!/bin/bash
cut -d";" -f3 | grep -i -c "$1"
