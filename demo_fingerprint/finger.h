#ifndef FINGER_H
#define FINGER_H

#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libfprint/fprint.h>
#include <QDebug>
struct fp_dscv_dev *discover_device(struct fp_dscv_dev **discovered_devs);
struct fp_print_data *enroll(struct fp_dev *dev);
int verify(struct fp_dev *dev, struct fp_print_data *data);


#endif // FINGER_H
