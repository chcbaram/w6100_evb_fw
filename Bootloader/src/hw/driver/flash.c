/*
 * flash.c
 *
 *  Created on: 2019. 6. 3.
 *      Author: Baram
 */


#include "flash.h"


#define FLASH_MAX_SECTOR          256


typedef struct
{
  int16_t  index;
  uint32_t addr;
  uint32_t length;
} flash_tbl_t;


flash_tbl_t flash_tbl[FLASH_MAX_SECTOR];


void flashInit(void)
{
  for (int i=0; i<FLASH_MAX_SECTOR; i++)
  {
    flash_tbl[i].index  = i;
    flash_tbl[i].addr   = 0x08000000 + i*2048;
    flash_tbl[i].length = 2048;
  }
}

bool flashErase(uint32_t addr, uint32_t length)
{
  bool ret = true;

  int32_t start_sector = -1;
  int32_t end_sector = -1;


  HAL_FLASH_Unlock();

  for (int i=0; i<FLASH_MAX_SECTOR; i++)
  {
    bool update = false;
    uint32_t start_addr;
    uint32_t end_addr;


    start_addr = flash_tbl[i].addr;
    end_addr   = flash_tbl[i].addr + flash_tbl[i].length - 1;

    if (start_addr >= addr && start_addr < (addr+length))
    {
      update = true;
    }
    if (end_addr >= addr && end_addr < (addr+length))
    {
      update = true;
    }

    if (addr >= start_addr && addr <= end_addr)
    {
      update = true;
    }
    if ((addr+length-1) >= start_addr && (addr+length-1) <= end_addr)
    {
      update = true;
    }


    if (update == true)
    {
      if (start_sector < 0)
      {
        start_sector = i;
      }
      end_sector = i;
    }
  }

  if (start_sector >= 0)
  {
    FLASH_EraseInitTypeDef EraseInit;
    uint32_t SectorError;
    HAL_StatusTypeDef status;


    EraseInit.PageAddress  = flash_tbl[start_sector].addr;
    EraseInit.Banks        = FLASH_BANK_1;
    EraseInit.NbPages      = (end_sector - start_sector) + 1;
    EraseInit.TypeErase    = FLASH_TYPEERASE_PAGES;


    status = HAL_FLASHEx_Erase(&EraseInit, &SectorError);
    if (status != HAL_OK)
    {
      ret = false;
    }
  }
  else
  {
    ret = false;
  }

  HAL_FLASH_Lock();

  return ret;
}

bool flashWrite(uint32_t addr, uint8_t *p_data, uint32_t length)
{
  bool ret = true;


  HAL_FLASH_Unlock();

  for (int i=0; i<length; i+=2)
  {
    HAL_StatusTypeDef status;
    uint16_t data;

    data  = p_data[i+0];
    data |= p_data[i+1] << 8;

    status = HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, addr + i, (uint64_t)data);
    if (status != HAL_OK)
    {
      ret = false;
      break;
    }
  }

  HAL_FLASH_Lock();

  return ret;
}

bool flashRead(uint32_t addr, uint8_t *p_data, uint32_t length)
{
  bool ret = true;
  uint8_t *p_byte = (uint8_t *)addr;


  for (int i=0; i<length; i++)
  {
    p_data[i] = p_byte[i];
  }

  return ret;
}
