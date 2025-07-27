
CFLAGS ?= -std=c11 -Wall -Wextra -Wno-unused-parameter

PKG_CONFIG ?= pkg-config

SCLYR_INCLUDE_DIR := $(PWD)/include
SCLYR_SOURCE_DIR := $(PWD)/source

CFLAGS += -I $(SCLYR_INCLUDE_DIR)

SCLYR_BUILD_DIR := $(PWD)/build

PKG_CONFIG_LIBRARIES := wayland-client

PKG_CONFIG_CFLAGS := $(shell $(PKG_CONFIG) --cflags $(PKG_CONFIG_LIBRARIES))
PKG_CONFIG_LDFLAGS := $(shell $(PKG_CONFIG) --libs $(PKG_CONFIG_LIBRARIES))

CFLAGS += $(PKG_CONFIG_CFLAGS)
LDFLAGS += $(PKG_CONFIG_LDFLAGS)

C_HEADER_FILES := $(shell find $(SCLYR_INCLUDE_DIR) -name *.h)
C_SOURCE_FILES := $(shell find $(SCLYR_SOURCE_DIR) -name *.c)

all: sclyr

sclyr: $(C_HEADER_FILES) $(C_SOURCE_FILES)
	$(CC) $(CFLAGS) -o $(SCLYR_BUILD_DIR)/$@ $(C_SOURCE_FILES) $(LDFLAGS)