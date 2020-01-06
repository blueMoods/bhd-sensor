/*******************************************************************************

    Driver for HC_SR501
    引脚连接：12

*******************************************************************************/

#ifndef __HC_SR501_H__
#define __HC_SR501_H__

/**
 * HC-SR501 callback
 * @param  up   true: someone is in range
 *              false: None is in range
 */
typedef void (* hc_sr501_cb_t)(bool up);

/**
 * Init HC-SR501 module
 * @param cb    When someone is in/out range,
 *              the callback will be called.
 */
void hc_sr501_init(hc_sr501_cb_t cb);

#endif