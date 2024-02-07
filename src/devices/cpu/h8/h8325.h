// license:BSD-3-Clause
// copyright-holders:Olivier Galibert
/***************************************************************************

    h8325.h

    H8/325 family emulation

    H8-300-based mcus.

    Variant         ROM        RAM
    H8/3257         60K         2K
    H8/3256         48K         2K
    H8/325          32K         1K
    H8/324          24K         1K
    H8/323          16K         512B
    H8/322          8K          256B

***************************************************************************/

#ifndef MAME_CPU_H8_H8325_H
#define MAME_CPU_H8_H8325_H

#pragma once

#include "h8.h"
#include "h8_intc.h"
#include "h8_port.h"
#include "h8_timer8.h"
#include "h8_timer16.h"
#include "h8_sci.h"

class h8325_device : public h8_device {
public:
	h8325_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock);

	auto read_port1()  { return m_read_port [PORT_1].bind(); }
	auto write_port1() { return m_write_port[PORT_1].bind(); }
	auto read_port2()  { return m_read_port [PORT_2].bind(); }
	auto write_port2() { return m_write_port[PORT_2].bind(); }
	auto read_port3()  { return m_read_port [PORT_3].bind(); }
	auto write_port3() { return m_write_port[PORT_3].bind(); }
	auto read_port4()  { return m_read_port [PORT_4].bind(); }
	auto write_port4() { return m_write_port[PORT_4].bind(); }
	auto read_port5()  { return m_read_port [PORT_5].bind(); }
	auto write_port5() { return m_write_port[PORT_5].bind(); }
	auto read_port6()  { return m_read_port [PORT_6].bind(); }
	auto write_port6() { return m_write_port[PORT_6].bind(); }
	auto read_port7()  { return m_read_port [PORT_7].bind(); }
	auto write_port7() { return m_write_port[PORT_7].bind(); }

	uint8_t syscr_r();
	void syscr_w(uint8_t data);
	uint8_t mdcr_r();

protected:
	h8325_device(const machine_config &mconfig, device_type type, const char *tag, device_t *owner, uint32_t clock, uint32_t start);

	required_device<h8325_intc_device> m_intc;
	required_device<h8_port_device> m_port1;
	required_device<h8_port_device> m_port2;
	required_device<h8_port_device> m_port3;
	required_device<h8_port_device> m_port4;
	required_device<h8_port_device> m_port5;
	required_device<h8_port_device> m_port6;
	required_device<h8_port_device> m_port7;
	required_device<h8_timer8_channel_device> m_timer8_0;
	required_device<h8_timer8_channel_device> m_timer8_1;
	required_device<h8_timer16_device> m_timer16;
	required_device<h8325_timer16_channel_device> m_timer16_0;

	uint8_t m_syscr;
	uint32_t m_ram_start;

	virtual void update_irq_filter() override;
	virtual void interrupt_taken() override;
	virtual void irq_setup() override;
	virtual void internal_update(uint64_t current_time) override;
	virtual void device_add_mconfig(machine_config &config) override;
	void map(address_map &map);

	virtual void device_start() override;
	virtual void device_reset() override;
	virtual void execute_set_input(int inputnum, int state) override;
};

class h83256_device : public h8325_device {
public:
	h83256_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock);
};

class h83257_device : public h8325_device {
public:
	h83257_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock);
};

class h8324_device : public h8325_device {
public:
	h8324_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock);
};

class h8323_device : public h8325_device {
public:
	h8323_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock);
};

class h8322_device : public h8325_device {
public:
	h8322_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock);
};

DECLARE_DEVICE_TYPE(H83257, h83257_device)
DECLARE_DEVICE_TYPE(H83256, h83256_device)
DECLARE_DEVICE_TYPE(H8325, h8325_device)
DECLARE_DEVICE_TYPE(H8324, h8324_device)
DECLARE_DEVICE_TYPE(H8323, h8323_device)
DECLARE_DEVICE_TYPE(H8322, h8322_device)

#endif // MAME_CPU_H8_H8325_H
