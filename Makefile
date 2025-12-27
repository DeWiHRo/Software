# ===== Controller & Takt =====
MCU     = atmega32
F_CPU   = 1000000UL

# ===== Fuses (ATmega32) =====
# Beispiel:
# - interner 1 MHz RC-Oszillator
# - SPIEN aktiv
# - kein CKDIV8
LFUSE = 0xE1
HFUSE = 0x99

# ===== Tools =====
CC      = avr-gcc
OBJCOPY = avr-objcopy
AVRDUDE = avrdude

# ===== Verzeichnisse =====
SRC_DIR     = src
INC_DIR     = headers
BUILD_DIR   = build

# ===== Dateien =====
TARGET  = main
SRC     = $(wildcard $(SRC_DIR)/*.c)
OBJ     = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))
DEP     = $(OBJ:.o=.d)
ELF     = $(BUILD_DIR)/$(TARGET).elf
HEX     = $(BUILD_DIR)/$(TARGET).hex

# ===== Compiler-Flags =====
CFLAGS  = -mmcu=$(MCU) -DF_CPU=$(F_CPU)
CFLAGS += -Os -Wall -Wextra -std=gnu99
CFLAGS += -I$(INC_DIR)
CFLAGS += -MMD -MP

# ===== Programmer / Upload =====
PROGRAMMER = avrispmkII
PORT       = COM4
BAUD       = 115200

# AVRDUDE_FLAGS = -p $(MCU) -c $(PROGRAMMER) -P $(PORT) -b $(BAUD)
AVRDUDE_FLAGS = -p $(MCU) -c $(PROGRAMMER)

# ====== Standardziel ======
all: $(BUILD_DIR) $(HEX)

# ====== Build-Verzeichnis ======
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# ====== Linken ======
$(ELF): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

# ====== HEX erzeugen ======
$(HEX): $(ELF)
	$(OBJCOPY) -O ihex -R .eeprom $< $@

# ====== Kompilieren ======
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# ====== Flashen ======
flash: $(HEX)
	$(AVRDUDE) $(AVRDUDE_FLAGS) \
		-U flash:w:$(HEX):i

# ====== Fuses schreiben ======
fuses:
	$(AVRDUDE) $(AVRDUDE_FLAGS) \
		-U lfuse:w:$(LFUSE):m \
		-U hfuse:w:$(HFUSE):m

# ====== Fuses lesen ======
read-fuses:
	$(AVRDUDE) $(AVRDUDE_FLAGS) \
		-U lfuse:r:-:h \
		-U hfuse:r:-:h

# ====== Flash + Fuses ======
program: $(HEX)
	$(AVRDUDE) $(AVRDUDE_FLAGS) \
		-U flash:w:$(HEX):i \
		-U lfuse:w:$(LFUSE):m \
		-U hfuse:w:$(HFUSE):m

# ====== Aufräumen ======
clean:
	rm -rf $(BUILD_DIR) *.elf *.hex

# ====== Header-Abhängigkeiten ======
-include $(DEP)
