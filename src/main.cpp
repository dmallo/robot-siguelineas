#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>

//#define LED_PIN GPIO_NUM_2
constexpr gpio_num_t LED_PIN = GPIO_NUM_2;
constexpr gpio_num_t BUTTON_PIN = GPIO_NUM_4;

extern "C" void app_main();

void app_main()
{

    // Setup
    gpio_config_t config_out;
    config_out.mode = GPIO_MODE_OUTPUT;
    config_out.pin_bit_mask = 1 << LED_PIN;
    config_out.intr_type = GPIO_INTR_DISABLE;
    config_out.pull_down_en = GPIO_PULLDOWN_DISABLE;
    config_out.pull_up_en = GPIO_PULLUP_DISABLE;
    gpio_config(&config_out);
    
    gpio_config_t config_in;
    config_in.mode = GPIO_MODE_INPUT;
    config_in.pin_bit_mask = 1 << BUTTON_PIN;
    config_in.pull_up_en = GPIO_PULLUP_ENABLE;
    config_in.pull_down_en = GPIO_PULLDOWN_DISABLE;
    gpio_config(&config_in);

    // Loop
    while (1)
    {

        if (gpio_get_level(BUTTON_PIN) == 1) {
            gpio_set_level(LED_PIN, 0);
        } else {
            gpio_set_level(LED_PIN, 1);
        }

        //gpio_set_level(LED_PIN, !gpio_get_level(BUTTON_PIN));

        /*gpio_set_level(LED_PIN, 1);
        vTaskDelay(pdMS_TO_TICKS(1000));
        gpio_set_level(LED_PIN, 0);
        vTaskDelay(pdMS_TO_TICKS(1000));*/
    }
    
}