//
// Created by amsakan on 03.11.25.
//
#include "HC-SR04.hh"

void HCSR04::init() const {
    HAL_TIM_Base_Start(tim_handle);
    HAL_GPIO_WritePin(trigger_port, trigger_pin, GPIO_PIN_RESET);
}


void HCSR04::measure(uint32_t* distance) const {
    HAL_GPIO_WritePin(trigger_port, trigger_pin, GPIO_PIN_SET);  // pull the TRIG pin HIGH
    __HAL_TIM_SET_COUNTER(tim_handle, 0);
    while (__HAL_TIM_GET_COUNTER(tim_handle) < 10) {}  // wait for 10 us
    HAL_GPIO_WritePin(trigger_port, trigger_pin, GPIO_PIN_RESET);  // pull the TRIG pin low

    uint32_t pMillis = HAL_GetTick(); // used this to avoid infinite while loop  (for timeout)
    // wait for the echo pin to go high
    while (!(HAL_GPIO_ReadPin (echo_port, echo_pin)) && pMillis + 10 >  HAL_GetTick()) {}
    uint32_t Value1 = __HAL_TIM_GET_COUNTER (tim_handle);

    pMillis = HAL_GetTick(); // used this to avoid infinite while loop (for timeout)
    // wait for the echo pin to go low
    while ((HAL_GPIO_ReadPin (echo_port, echo_pin)) && pMillis + 50 > HAL_GetTick()) {}
    uint32_t Value2 = __HAL_TIM_GET_COUNTER (tim_handle);

    *distance = (Value2-Value1)* 0.034/2;
    HAL_Delay(50);
}
