idf_component_register(SRCS "mpu60xx.c" "mpu_i2c.c" "main.c"
                    PRIV_REQUIRES spi_flash driver
                    INCLUDE_DIRS "")
