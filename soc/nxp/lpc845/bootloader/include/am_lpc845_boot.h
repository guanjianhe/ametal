/*******************************************************************************
*                                 AMetal
*                       ----------------------------
*                       innovating embedded platform
*
* Copyright (c) 2001-2018 Guangzhou ZHIYUAN Electronics Co., Ltd.
* All rights reserved.
*
* Contact information:
* web site:    http://www.zlg.cn/
*******************************************************************************/

/**
 * \file
 * \brief bootloader drivers for standard interface
 *
 * \internal
 * \par Modification history
 * - 1.00 18-11-15  yrh, first implementation
 * \endinternal
 */

#ifndef __AM_lpc845_BOOT_H
#define __AM_lpc845_BOOT_H

#include "am_boot.h"
//#include "hw/amhw_lpc84x_iap.h"
#include "am_boot_flash.h"

typedef struct am_lpc845_boot_devinfo {
    uint32_t  app_start_addr;      /**< \brief 应用代码区起始地址*/
    uint32_t  update_flag_addr;    /**< \brief 升级标志的存放地址，一般是放在应用代码区起始地址的前4字节*/
    uint32_t  flash_start_addr;    /**< \brief flash的起始地址*/
    uint32_t  flash_size;          /**< \brief flash的大小 */

    uint32_t  update_start_addr;   /**< \brief 应用代码升级区（备份）地址 */
    uint32_t  ram_start_addr;      /**< \brief ram起始地址 */
    uint32_t  ram_size;            /**< \brief ram的大小 */

    void (*pfn_plfm_init)(void);   /**< \brief 平台初始化函数 */

    void (*pfn_plfm_deinit)(void); /**< \brief 平台去初始化函数 */
}am_lpc845_boot_devinfo_t;

typedef struct am_lpc845_boot_dev {
    am_lpc845_boot_devinfo_t *p_devinfo;
    am_boot_flash_handle_t    flash_handle;   /**< \brief flash操作句柄 */

}am_lpc845_boot_dev_t;

/**
 * \brief 初始化BootLoader，返回BootLoader标准服务操作句柄
 *
 * \param[in] p_dev     : 指向BootLoader设备的指针
 * \param[in] p_devinfo : 指向BootLoader设备信息常量的指针
 *
 * \return BootLoader标准服务操作句柄，值为NULL时表明初始化失败
 */
int am_lpc845_boot_init(am_lpc845_boot_dev_t      *p_dev,
                        am_lpc845_boot_devinfo_t  *p_devinfo,
                        am_boot_flash_handle_t     flash_handle);


#endif /* __AM_lpc845_BOOT_H */
