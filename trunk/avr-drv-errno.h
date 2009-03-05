/*
 * avr-drv-errno.h
 *
 *  Created on: 2009-03-04
 *      Author: fnadeau
 */

#ifndef AVRDRVERRNO_H_
#define AVRDRVERRNO_H_

#include <errno.h>

#define EINVAL 22 /*!< Invalid argument. */

#define EBAUDRATE 128 /*!< Requested baud rate is not attainable. */
#define ETXDISABLED 129 /*!< Transmission is not enabled. */
#define ERXDISABLED 130 /*!< Reception is not enabled. */
#define ERXPARITY 131
#define ERXOVERRUN 132
#define ERXFRAM 133
#define ERXMULTI 134


#endif /* AVRDRVERRNO_H_ */
