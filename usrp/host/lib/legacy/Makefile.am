#
#  USRP - Universal Software Radio Peripheral
# 
#  Copyright (C) 2003,2004,2006,2007,2008,2009 Free Software Foundation, Inc.
# 
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 3 of the License, or
#  (at your option) any later version.
# 
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
# 
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin Street, Boston, MA  02110-1301  USA
# 

include $(top_srcdir)/Makefile.common

common_INCLUDES = $(USRP_INCLUDES)

lib_LTLIBRARIES = libusrp.la

libusrp_la_common_LDFLAGS = $(NO_UNDEFINED) -version-info 0:0:0 $(BOOST_LDFLAGS)

libusrp_la_common_LIBADD = 		\
	$(USB_LIBS) 			\
	$(BOOST_THREAD_LIB)		\
	../../misc/libmisc.la

# darwin fusb requires omnithreads
if FUSB_TECH_darwin
AM_CPPFLAGS = $(common_INCLUDES) $(OMNITHREAD_INCLUDES) $(BOOST_CPPFLAGS) $(WITH_INCLUDES)
libusrp_la_LIBADD = $(libusrp_la_common_LIBADD) $(OMNITHREAD_LA)
libusrp_la_LDFLAGS = $(libusrp_la_common_LDFLAGS) -framework CoreFoundation
else
AM_CPPFLAGS = $(common_INCLUDES) $(BOOST_CPPFLAGS) $(WITH_INCLUDES)
libusrp_la_LIBADD = $(libusrp_la_common_LIBADD)
libusrp_la_LDFLAGS = $(libusrp_la_common_LDFLAGS)
endif

EXTRA_DIST = 				\
	std_paths.h.in			\
	usrp_dbid.dat			

BUILT_SOURCES = 			\
	usrp_dbid.h			\
	usrp_dbid.cc			\
	usrp_dbid.py			


# ----------------------------------------------------------------
# FUSB_TECH is set at configure time by way of
#   usrp/config/usrp_fusb_tech.m4.
#   It indicates which fast usb strategy we should be building.
#   We currently implement "generic", "darwin", "win32" and "linux"


generic_CODE = 				\
	fusb_generic.cc			\
	fusb_sysconfig_generic.cc

darwin_CODE =				\
	fusb_darwin.cc			\
	fusb_sysconfig_darwin.cc 	\
	README_OSX			\
	circular_buffer.h		\
	circular_linked_list.h		\
	darwin_libusb.h			\
	mld_threads.h			

win32_CODE =				\
	fusb_win32.cc			\
	fusb_sysconfig_win32.cc 	

linux_CODE =				\
	fusb_linux.cc			\
	fusb_sysconfig_linux.cc 	

ra_wb_CODE =				\
	fusb_ra_wb.cc			\
	fusb_sysconfig_ra_wb.cc


#
# include each <foo>_CODE entry here...
#
EXTRA_libusrp_la_SOURCES =		\
	$(generic_CODE)			\
	$(darwin_CODE)			\
	$(win32_CODE)			\
	$(linux_CODE)			\
	$(ra_wb_CODE)


# work around automake deficiency
libusrp_la_common_SOURCES = 		\
	fusb.cc				\
	md5.c				\
	usrp_basic.cc			\
	usrp_config.cc			\
	usrp_dbid.cc			\
	usrp_local_sighandler.cc	\
	usrp_prims.cc			\
	usrp_standard.cc		\
	db_boards.cc			\
	db_base.cc			\
	db_basic.cc			\
	db_tv_rx.cc			\
	db_flexrf.cc			\
	db_flexrf_mimo.cc		\
	db_dbs_rx.cc			\
	db_xcvr2450.cc			\
	db_dtt754.cc			\
	db_dtt768.cc			\
	db_util.cc

#	db_wbx.cc


if FUSB_TECH_generic
libusrp_la_SOURCES = $(libusrp_la_common_SOURCES) $(generic_CODE)
endif

if FUSB_TECH_darwin
libusrp_la_SOURCES = $(libusrp_la_common_SOURCES) $(darwin_CODE)
endif

if FUSB_TECH_win32
libusrp_la_SOURCES = $(libusrp_la_common_SOURCES) $(win32_CODE)
endif

if FUSB_TECH_linux
libusrp_la_SOURCES = $(libusrp_la_common_SOURCES) $(linux_CODE)
endif

if FUSB_TECH_ra_wb
libusrp_la_SOURCES = $(libusrp_la_common_SOURCES) $(ra_wb_CODE)
endif

include_HEADERS = 			\
	db_base.h			\
	db_basic.h			\
	db_dbs_rx.h			\
	db_dtt754.h			\
	db_dtt768.h			\
	db_flexrf.h			\
	db_flexrf_mimo.h		\
	db_tv_rx.h			\
	db_util.h			\
	db_xcvr2450.h			\
	usrp_basic.h			\
	usrp_bytesex.h			\
	usrp_config.h			\
	usrp_dbid.h			\
	usrp_prims.h			\
	usrp_slots.h			\
	usrp_standard.h			\
	usrp_subdev_spec.h		\
	usrp_tune_result.h		

noinst_HEADERS =			\
	ad9862.h			\
	db_base_impl.h			\
	db_boards.h			\
	db_wbx.h			\
	fusb.h				\
	fusb_darwin.h			\
	fusb_generic.h			\
	fusb_linux.h			\
	fusb_ra_wb.h			\
	fusb_win32.h			\
	md5.h				\
	rate_to_regval.h		\
	usrp_local_sighandler.h		

usrppython_PYTHON =			\
	usrp_dbid.py			

noinst_PYTHON =				\
	gen_usrp_dbid.py		\
	check_data.py			\
	dump_data.py

swiginclude_HEADERS = db_base.i

# common way for generating sources from templates when using
# BUILT_SOURCES, using parallel build protection.
gen_sources = $(BUILT_SOURCES)
gen_sources_deps = gen_usrp_dbid.py usrp_dbid.dat
par_gen_command = PYTHONPATH=$(top_srcdir)/usrp/src srcdir=$(srcdir) $(PYTHON) $(srcdir)/gen_usrp_dbid.py $(srcdir)/usrp_dbid.dat
include $(top_srcdir)/Makefile.par.gen
