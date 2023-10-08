#!/bin/sh
ifconfig | grep "^\tether" | tr -d '\t' | sed 's/ether //g' | sed 's/ $//g'
