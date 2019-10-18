//
// Created by tobi on 11.12.18.
//

#include "LED.h"


LED::LED(const GPIO_Pair &gpio, const bool _pol) : gp(gpio), pol(_pol){
    init();
}

void LED::init() {
    init_gpio_clk();
    init_pin();
}
void LED::init_gpio_clk() {
    if (gp.bank == GPIOA) {
        __HAL_RCC_GPIOA_CLK_ENABLE()
                ;
    } else if (gp.bank == GPIOB) {
        __HAL_RCC_GPIOB_CLK_ENABLE()
                ;
    } else if (gp.bank == GPIOC) {
        __HAL_RCC_GPIOC_CLK_ENABLE()
                ;
    } else if (gp.bank == GPIOD) {
        __HAL_RCC_GPIOD_CLK_ENABLE()
                ;
    } else if (gp.bank == GPIOE) {
        __HAL_RCC_GPIOE_CLK_ENABLE()
                ;
    } else if (gp.bank== GPIOF) {
        __HAL_RCC_GPIOF_CLK_ENABLE()
                ;
    } else if (gp.bank == GPIOG) {
        __HAL_RCC_GPIOG_CLK_ENABLE()
                ;
    } else if (gp.bank == GPIOH) {
        __HAL_RCC_GPIOH_CLK_ENABLE()
                ;
    }
}
void LED::init_pin() {
    GPIO_InitTypeDef gpio_tdef;
    gpio_tdef.Mode = GPIO_MODE_AF_PP;
    gpio_tdef.Pin = gp.pin;
    gpio_tdef.Pull = GPIO_PULLDOWN;
    gpio_tdef.Speed = GPIO_SPEED_HIGH;
    HAL_GPIO_Init(gp.bank, &gpio_tdef);
}
void LED::set() {
    if(pol){
        HAL_GPIO_WritePin(gp.bank, gp.pin, GPIO_PIN_SET);
    }else{
        HAL_GPIO_WritePin(gp.bank, gp.pin, GPIO_PIN_RESET);
    }

}
void LED::toggle() {
    HAL_GPIO_TogglePin(gp.bank, gp.pin);
}
void LED::off() {
    if(!pol){
        HAL_GPIO_WritePin(gp.bank, gp.pin, GPIO_PIN_SET);
    }else{
        HAL_GPIO_WritePin(gp.bank, gp.pin, GPIO_PIN_RESET);
    }
}
