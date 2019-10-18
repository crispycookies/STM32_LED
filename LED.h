//
// Created by tobi on 11.12.18.
//

#ifndef DRONE_LED_H
#define DRONE_LED_H

#include "../../../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal.h"
#include "../../../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_tim.h"
#include "../../../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_gpio.h"

struct GPIO_Pair {
    uint16_t pin = 0;
    GPIO_TypeDef * bank = nullptr;
};

class LED{
public:
    LED(const GPIO_Pair & gpio, const bool _pol = false);
    virtual ~LED() = default;
    void set();
    void toggle();
    void off();
protected:
    void init();
    void init_gpio_clk();
    void init_pin();
    const GPIO_Pair gp;
    const bool pol;
};


#endif //DRONE_LED_H
