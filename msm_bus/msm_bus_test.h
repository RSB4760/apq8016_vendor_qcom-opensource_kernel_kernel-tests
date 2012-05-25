#ifndef __MSM_BUS_TEST__
#define __MSM_BUS_TEST__

#include <linux/ioctl.h>
#define DEBUG
#define MSM_BUS_IOC_MAGIC 0x80
#define TEST_SLAVE_ID_KEY 512
#define NUM_USECASES 10
#define NUM_VECTORS 5

/**
 * The test enums do not contain the gateway master/slave IDs. Hence, they
 * differ from the enums used in boards file.
 * This is done so that random master/slave pairs can be created for
 * testing.
 */
enum msm_bus_test_fabric_master_type {
	MSM_BUS_TEST_MASTER_FIRST = 1,
	MSM_BUS_TEST_MASTER_AMPSS_M0 = 1,
	MSM_BUS_TEST_MASTER_AMPSS_M1,

	MSM_BUS_TEST_MASTER_SPS = 6,
	MSM_BUS_TEST_MASTER_ADM0_PORT0,
	MSM_BUS_TEST_MASTER_ADM0_PORT1,
	MSM_BUS_TEST_SYSTEM_MASTER_ADM1_PORT0,
	MSM_BUS_TEST_MASTER_ADM1_PORT1,
	MSM_BUS_TEST_MASTER_LPASS_PROC,
	MSM_BUS_TEST_MASTER_MSS_PROCI,
	MSM_BUS_TEST_MASTER_MSS_PROCD,
	MSM_BUS_TEST_MASTER_MSS_MDM_PORT0,
	MSM_BUS_TEST_MASTER_LPASS,
	MSM_BUS_TEST_MASTER_ADM1_CI = 19,
	MSM_BUS_TEST_MASTER_ADM0_CI,
	MSM_BUS_TEST_MASTER_MSS_MDM_PORT1,

	MSM_BUS_TEST_MASTER_MDP_PORT0,
	MSM_BUS_TEST_MASTER_MDP_PORT1,
	MSM_BUS_TEST_MMSS_MASTER_ADM1_PORT0,
	MSM_BUS_TEST_MASTER_ROTATOR,
	MSM_BUS_TEST_MASTER_GRAPHICS_3D,
	MSM_BUS_TEST_MASTER_JPEG_DEC,
	MSM_BUS_TEST_MASTER_GRAPHICS_2D_CORE0,
	MSM_BUS_TEST_MASTER_VFE,
	MSM_BUS_TEST_MASTER_VPE,
	MSM_BUS_TEST_MASTER_JPEG_ENC,
	MSM_BUS_TEST_MASTER_GRAPHICS_2D_CORE1,
	MSM_BUS_TEST_MASTER_HD_CODEC_PORT0 = 34,
	MSM_BUS_TEST_MASTER_HD_CODEC_PORT1,

	MSM_BUS_TEST_MASTER_SPDM,
	MSM_BUS_TEST_MASTER_RPM,

	MSM_BUS_TEST_MASTER_LAST = MSM_BUS_TEST_MASTER_RPM,
};

enum msm_bus_test_fabric_slave_type {
	MSM_BUS_TEST_SLAVE_FIRST = TEST_SLAVE_ID_KEY,
	MSM_BUS_TEST_SLAVE_EBI_CH0 = TEST_SLAVE_ID_KEY,
	MSM_BUS_TEST_SLAVE_AMPSS_L2,

	MSM_BUS_TEST_SLAVE_SPS,
	MSM_BUS_TEST_SLAVE_SYSTEM_IMEM,
	MSM_BUS_TEST_SLAVE_AMPSS,
	MSM_BUS_TEST_SLAVE_MSS,
	MSM_BUS_TEST_SLAVE_LPASS,

	MSM_BUS_TEST_SLAVE_SMI,
	MSM_BUS_TEST_SLAVE_MM_IMEM,

	MSM_BUS_TEST_SLAVE_SPDM,
	MSM_BUS_TEST_SLAVE_RPM,
	MSM_BUS_TEST_SLAVE_RPM_MSG_RAM,
	MSM_BUS_TEST_SLAVE_MPM,
	MSM_BUS_TEST_SLAVE_PMIC1_SSBI1_A,
	MSM_BUS_TEST_SLAVE_PMIC1_SSBI1_B,
	MSM_BUS_TEST_SLAVE_PMIC1_SSBI1_C,
	MSM_BUS_TEST_SLAVE_PMIC2_SSBI2_A,
	MSM_BUS_TEST_SLAVE_PMIC2_SSBI2_B,

	MSM_BUS_TEST_SLAVE_GSBI1_UART,
	MSM_BUS_TEST_SLAVE_GSBI2_UART,
	MSM_BUS_TEST_SLAVE_GSBI3_UART,
	MSM_BUS_TEST_SLAVE_GSBI4_UART,
	MSM_BUS_TEST_SLAVE_GSBI5_UART,
	MSM_BUS_TEST_SLAVE_GSBI6_UART,
	MSM_BUS_TEST_SLAVE_GSBI7_UART,
	MSM_BUS_TEST_SLAVE_GSBI8_UART,
	MSM_BUS_TEST_SLAVE_GSBI9_UART,
	MSM_BUS_TEST_SLAVE_GSBI10_UART,
	MSM_BUS_TEST_SLAVE_GSBI11_UART,
	MSM_BUS_TEST_SLAVE_GSBI12_UART,
	MSM_BUS_TEST_SLAVE_GSBI1_QUP,
	MSM_BUS_TEST_SLAVE_GSBI2_QUP,
	MSM_BUS_TEST_SLAVE_GSBI3_QUP,
	MSM_BUS_TEST_SLAVE_GSBI4_QUP,
	MSM_BUS_TEST_SLAVE_GSBI5_QUP,
	MSM_BUS_TEST_SLAVE_GSBI6_QUP,
	MSM_BUS_TEST_SLAVE_GSBI7_QUP,
	MSM_BUS_TEST_SLAVE_GSBI8_QUP,
	MSM_BUS_TEST_SLAVE_GSBI9_QUP,
	MSM_BUS_TEST_SLAVE_GSBI10_QUP,
	MSM_BUS_TEST_SLAVE_GSBI11_QUP,
	MSM_BUS_TEST_SLAVE_GSBI12_QUP,
	MSM_BUS_TEST_SLAVE_EBI2_NAND,
	MSM_BUS_TEST_SLAVE_EBI2_CS0,
	MSM_BUS_TEST_SLAVE_EBI2_CS1,
	MSM_BUS_TEST_SLAVE_EBI2_CS2,
	MSM_BUS_TEST_SLAVE_EBI2_CS3,
	MSM_BUS_TEST_SLAVE_EBI2_CS4,
	MSM_BUS_TEST_SLAVE_EBI2_CS5,
	MSM_BUS_TEST_SLAVE_USB_FS1,
	MSM_BUS_TEST_SLAVE_USB_FS2,
	MSM_BUS_TEST_SLAVE_TSIF,
	MSM_BUS_TEST_SLAVE_MSM_TSSC,
	MSM_BUS_TEST_SLAVE_MSM_PDM,
	MSM_BUS_TEST_SLAVE_MSM_DIMEM,
	MSM_BUS_TEST_SLAVE_MSM_TCSR,
	MSM_BUS_TEST_SLAVE_MSM_PRNG,
	MSM_BUS_TEST_SLAVE_LAST = MSM_BUS_TEST_SLAVE_MSM_PRNG,
};


struct msm_bus_test_vectors {
	int src; /* Master */
	int dst; /* Slave */
	unsigned int ab; /* Arbitrated bandwidth */
	unsigned int ib; /* Instantaneous bandwidth */
};

struct msm_bus_test_paths {
	int num_paths;
	struct msm_bus_test_vectors vectors[NUM_VECTORS];
};

struct msm_bus_test_scale_pdata {
	struct msm_bus_test_paths usecase[NUM_USECASES];
	int num_usecases;
	const char *name;
	unsigned int active_only;
};

struct msm_bus_test_cldata {
	struct msm_bus_test_scale_pdata pdata;
	uint32_t clid;
	uint32_t pdatah;
};

struct msm_bus_test_update_req_data {
	uint32_t clid;
	uint32_t index;
};
#define MSM_BUS_TEST_IOC_MAGIC 0x80

#define MSM_BUS_TEST_REG_CL _IOWR(MSM_BUS_TEST_IOC_MAGIC, 2, \
	struct msm_bus_test_cldata)

#define MSM_BUS_TEST_UNREG_CL _IOWR(MSM_BUS_TEST_IOC_MAGIC, 3, \
	struct msm_bus_test_cldata)

#define MSM_BUS_TEST_UPDATE_REQ _IOWR(MSM_BUS_TEST_IOC_MAGIC, 4, \
	struct msm_bus_test_update_req_data)

#define MSM_BUS_TEST_GET_CLID _IOWR(MSM_BUS_TEST_IOC_MAGIC, 5, uint32_t)
#define MSM_BUS_TEST_GET_RET _IOWR(MSM_BUS_TEST_IOC_MAGIC, 6, int)


#endif /*__MSM_BUS_TEST__*/
