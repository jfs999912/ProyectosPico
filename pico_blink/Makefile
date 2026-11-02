TARGET    = pico_blink
BUILD_DIR = build
UF2       = $(BUILD_DIR)/$(TARGET).uf2

.PHONY: all flash clean

all: $(UF2)

$(UF2):
	@mkdir -p $(BUILD_DIR)
	@cd $(BUILD_DIR) && cmake .. && make -j2

flash: $(UF2)
	@echo "=========================================="
	@echo " Flasheando $(UF2) en RP2040..."
	@echo "=========================================="
	@pico-flash $(UF2)

clean:
	@rm -rf $(BUILD_DIR)
