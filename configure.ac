AC_PREREQ(2.64)

AC_INIT([kernel-tests],[1.0.0])
AM_INIT_AUTOMAKE([-Wall -Werror gnu foreign])
m4_ifdef([AM_PROG_AR], [AM_INIT_AUTOMAKE([-Wall -Werror gnu foreign -Wno-extra-portability -Wno-portability])])

AM_MAINTAINER_MODE

AC_CONFIG_HEADER([config.h])
AC_CONFIG_MACRO_DIR([m4])

# Checks for programs.
AC_PROG_CC
AM_PROG_CC_C_O
m4_ifdef([AM_PROG_AR], [AM_PROG_AR])
AC_PROG_LIBTOOL
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_MAKE_SET
AC_PROG_CXX

AC_ARG_WITH(sanitized-headers,
	AS_HELP_STRING([--with-sanitized-headers=DIR],
		[Specify the location of the sanitized Linux headers]),
	[CPPFLAGS="$CPPFLAGS -I$withval"])

AC_ARG_ENABLE(big-tests,
	AS_HELP_STRING([--enable-big-tests],
		[Include tests that use a lot of disk [default=yes]]),
	[case "${enableval}" in
	  yes) BIGTESTS=true ;;
	  no)  BIGTESTS=false ;;
	  *)   AC_MSG_ERROR([bad value ${enableval} for --enable-big-tests]) ;;
	esac],
	[BIGTESTS=true])
AM_CONDITIONAL(BIGTESTS, [test x$BIGTESTS = xtrue])

AC_ARG_WITH([kernel],
	AS_HELP_STRING([--with-kernel=DIR],
		[location of a built kernel; used for building kernel modules]),
	[case "${with_kernel}" in
	  yes|'') AC_MSG_ERROR([--with-kernel must specify a path]) ;;
	  no)     with_kernel= ;;
	  *)
		if [test ! -f ${with_kernel}/Makefile]; then
			AC_MSG_ERROR([bad value '${with_kernel}' for --with-kernel; cannot find '${with_kernel}/Makefile'])
		fi ;;
	esac])
if [test -z "${with_kernel}"]; then
	AC_MSG_WARN([no kernel specified; kernel modules will not be included])
else
	AC_SUBST([KERNEL_DIR], [${with_kernel}])
fi
AM_CONDITIONAL(KERNELMODULES, [test -n "${with_kernel}"])

msm_iommu_configured=no
autoconf="${with_kernel}/include/generated/autoconf.h"
if test -f ${autoconf}; then
	if grep -q "^#define CONFIG_MSM_IOMMU 1" ${autoconf}; then
		msm_iommu_configured=yes
	fi
fi

# Build G-Link Tests only if kernel module enabled
msm_glink_configured=no
autoconf="${with_kernel}/include/generated/autoconf.h"
if test -f ${autoconf}; then
	if grep -q "^#define CONFIG_MSM_GLINK 1" ${autoconf}; then
		msm_glink_configured=yes
	fi
fi

#
# Build all kernel tests by default
#
# To add new tests add ENABLE_KERNEL_TEST and update AC_CONFIG_FILES
#
# Tests which will be too large to fit in an initrd/initramfs should not
# be installed if the conditional BIGTESTS is false.
#

# ion
ENABLE_KERNEL_TEST([ion],[include the ion test (default=yes)])

# ipc_logging
ENABLE_KERNEL_TEST([ipc_logging],[include the ipc_logging test (default=yes)])

# memory_prof
ENABLE_KERNEL_TEST([memory_prof],[include the memory profiling test (default=yes)],[$msm_iommu_configured])

# msm-bus
ENABLE_KERNEL_TEST([msm-bus],[include the MSM bus test (default=yes)])

# sps
ENABLE_KERNEL_TEST([sps],[include the sps test (default=yes)])

# v4l2apps
ENABLE_KERNEL_TEST([v4l2apps],[include the v4l2apps test (default=no)],[no])

# watchdog
ENABLE_KERNEL_TEST([watchdog],[include the watchdog test (default=yes)])

# ocmem
ENABLE_KERNEL_TEST([ocmem],[include the ocmem test (default=yes)])

# iommu
ENABLE_KERNEL_TEST([iommu],[include the iommu test (default=yes)])

# ip_accelerator
ENABLE_KERNEL_TEST([ip_accelerator],[include the ip_accelerator test (default=yes)])

# bam_dmux_loopback
ENABLE_KERNEL_TEST([bam_dmux_loopback],[include the bam_dmux_loopback test (default=yes)])

# hrtimer
ENABLE_KERNEL_TEST([hrtimer],[include the hrtimer test (default=yes)])

#swp
ENABLE_KERNEL_TEST([swp],[include the swp test (default=yes)])

# ipi
ENABLE_KERNEL_TEST([ipi],[include the ipi test (default=yes)])

# page-nom
ENABLE_KERNEL_TEST([page-nom],[include the page-nom test (default=yes)])

# modsign
ENABLE_KERNEL_TEST([modsign],[include the modsign test (default=yes)])

# coresight
ENABLE_KERNEL_TEST([coresight],[include the coresight test (default=yes)])

# bus-timeout
ENABLE_KERNEL_TEST([bus-timeout],[include the bus-timeout test (default=yes)])

# abnormal_reset
ENABLE_KERNEL_TEST([abnormal_reset],[include the abnormal_reset test (default=yes)])

#glink
ENABLE_KERNEL_TEST([glink],[include the glink test (default=yes)], [$msm_glink_configured])

AC_SUBST([CFLAGS])
AC_SUBST([CC])

AC_CONFIG_FILES([
	Makefile
	bam_dmux_loopback/Makefile
	ion/Makefile
	ipc_logging/Makefile
	memory_prof/Makefile
	msm_bus/Makefile
	ocmem/Makefile
	msm_iommu/Makefile
	sps/Makefile
	coresight/Makefile
	coresight/byte-cntr/Makefile
	coresight/stm-trace-marker/Makefile
	coresight/stm/Makefile
	coresight/etm/Makefile
	coresight/cti/Makefile
	coresight/mult_trace/Makefile
	coresight/platform/Makefile
	coresight/profile/Makefile
	coresight/sink_switch/Makefile
	bus-timeout/Makefile
	abnormal_reset/Makefile
	v4l2apps/Makefile
	watchdog/Makefile
	ip_accelerator/Makefile
	hrtimer/Makefile
	swp/Makefile
	ipi/Makefile
	page-nom/Makefile
	modsign/Makefile
	glink/Makefile
	])
AC_OUTPUT
