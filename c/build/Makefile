ROOT ?= .

CC := gcc

CFLAGS := 
AFLAGS := 
LFLAGS := 

TARGET := test

SRC_FILES := $(shell find $(ROOT) -name "*.c")
HDR_FILES := $(shell find $(ROOT) -name "*.h")

BUILD_DIR := build
OBJS :=

all:$(TARGET)

add_flg = $(eval CFLAGS += -I$1)
HDRS := $(strip $(filter %.h,$(HDR_FILES)))
HDRS := $(dir $(HDRS))
$(if $(HDRS),$(foreach h,$(HDRS),$(call add_flg,$(h))))

define add_c_file
$(eval C_SRC := $(1:$(ROOT)/%=%)) \
$(eval COBJ := $(1:%.c=%.o)) \
$(eval COBJ := $(COBJ:$(ROOT)/%=%)) \
$(eval LOCALC := $(addprefix $(BUILD_DIR)/,$(COBJ))) \
$(eval OBJS += $(LOCALC)) \
$(if $(strip $(LOCALC)),$(eval $(LOCALC): $(C_SRC)
	@if [ ! -d $$(@D) ]; then mkdir -p $$(@D); fi
	@echo cc $$<
	@$(CC) $$(CFLAGS) -c $$< -o $$@))
endef

SRCS := $(strip $(filter %.c,$(SRC_FILES)))
$(if $(SRCS),$(foreach f,$(SRCS),$(call add_c_file,$(f))))

$(TARGET):$(OBJS) Makefile
	@echo --------------------------------
	@echo link $(TARGET)
	@$(CC) -o $(BUILD_DIR)/$@ $(LFLAGS) $(OBJS)



.PHONY:clean print
clean:
	rm -rf build

print:
	@echo $(OBJS)
	@echo $(CFLAGS)
