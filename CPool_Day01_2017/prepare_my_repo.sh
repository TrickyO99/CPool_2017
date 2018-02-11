#!/bin/bash
blih -u othmane.triki@epitech.eu repository create "$1"
blih -u othmane.triki@epitech.eu repository setacl "$1" ramassage-tek r
blih -u othmane.triki@epitech.eu repository getacl "$1"
