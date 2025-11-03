//
// Created by amsakan on 03.11.25.
//

#ifndef HC_SR04_HC_SR04_HH
#define HC_SR04_HC_SR04_HH
#include "stm32f1xx_hal.h"

class HCSR04 {
    GPIO_TypeDef* trigger_port;
    uint16_t trigger_pin;

    GPIO_TypeDef* echo_port;
    uint16_t echo_pin;

    TIM_HandleTypeDef* tim_handle;
public:
    explicit HCSR04(TIM_HandleTypeDef* tim_handle, GPIO_TypeDef* trigger_port, uint16_t trigger_pin, GPIO_TypeDef* echo_port, uint16_t echo_pin)
        :trigger_port(trigger_port), trigger_pin(trigger_pin), echo_port(echo_port), echo_pin(echo_pin), tim_handle(tim_handle) {}

    void init() const;
    void measure(uint32_t* distance) const;
};
#endif //HC_SR04_HC_SR04_HH