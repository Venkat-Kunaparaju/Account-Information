#!/bin/bash

#1->username, 2->email, 3->password
printf "|$1-$3|$2-$3|\n" >> "accountStorage.txt"


exit $?