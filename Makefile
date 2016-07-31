.PHONY: all
all:
	(cd build;make;make stm32.bin)

.PHONY: upload
upload:
	st-flash write build/stm32.bin 0x8000000
