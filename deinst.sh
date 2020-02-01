#!/bin/bash
make -f couponlib.mak clean
make -f coupon.mak clean
make -f etauscoup.mak clean
make -f fibocoup.mak clean
make -f lfsrcoup.mak clean
make -f rucoupon.mak clean
make -f sinecoup.mak clean
make -f bitcoup.mak clean
make -f gslcoup.mak clean
make -f diecoup.mak clean
# remove test output
rm -f allgsl.out alldie.out
