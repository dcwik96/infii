#!/bin/bash
awk '$2 == search' search=$1 $2
