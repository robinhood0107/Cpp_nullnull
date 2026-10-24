


int main() {
    {
        Monitor monitor;
    }
    std::cout << "--------------------------" << std::endl;
    {
        Printer printer;
    }
    std::cout << "--------------------------" << std::endl;
    {
        LED_Monitor led_monitor;
        LCD_Monitor lcd_monitor;
    }
}
