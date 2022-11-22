LIBPATH := lib/$(LIB)

INCLUDES += -I$(LIBPATH)/inc

$(LIB)_CSOURCES += \
	$(LIBPATH)/uart.c \

