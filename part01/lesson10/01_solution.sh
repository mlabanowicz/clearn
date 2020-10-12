#!/bin/sh
gawk '{printf("%d\n", length($0))}'
