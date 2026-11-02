TARGET    = pico_pwm
BUILD_DIR = build
UF2       = $(BUILD_DIR)/$(TARGET).uf2

.PHONY: all build flash clean

all: build

# 1. Configura con CMake y compila en build/
build:
	@mkdir -p $(BUILD_DIR)
	@cmake -B $(BUILD_DIR) -S .
	@cmake --build $(BUILD_DIR) -j2

# 2. Compila si hay cambios y flashea el archivo .uf2
flash: build
	@if [ ! -f $(UF2) ]; then \
		echo "Error: No se encontró $(UF2)"; \
		exit 1; \
	fi
	@echo "=========================================="
	@echo " Flasheando $(UF2) con pico-flash..."
	@echo "=========================================="
	@pico-flash $(UF2)

# 3. Limpieza completa de la caché de build
clean:
	@echo "Limpiando directorio $(BUILD_DIR)..."
	@rm -rf $(BUILD_DIR)
