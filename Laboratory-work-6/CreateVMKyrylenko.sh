#!/bin/bash

# =========================================================================
# File: CreateVMKyrylenko.sh
# Lab: OS Laboratory Work #5, #6
# Author: Kyrylenko
# Description: Script to create and configure a VirtualBox VM via CLI
# Parameters: RAM=2458MB, DISK=9800MB (9.8 GB)
# =========================================================================

VM_NAME="Linux of Kyrylenko 2"
DISK_SIZE=9800
ISO_PATH="C:\Users\winli\Downloads\ubuntu-14.04.6-server-amd64.iso"

# Крок 1. Реєстрація віртуальної машини (з іменем та типом ОС)
VBoxManage createvm --name "$VM_NAME" --ostype Ubuntu14_LTS_64 --register

# Крок 2. Встановлення апаратних властивостей
# [cite_start]ОЗП (2458 МБ) та CPU (1 ядро) [cite: 2299, 2300]
VBoxManage modifyvm "$VM_NAME" --memory 2458 --cpus 1

# Налаштування графічного контролера та VRAM (рекомендовано для Ubuntu Server)
VBoxManage modifyvm "$VM_NAME" --graphicscontroller VBoxVGA --vram 16

# [cite_start]Налаштування мережевої карти 1 (NAT) та Port Forwarding (SSH 1234 -> 22) [cite: 2301, 2302]
VBoxManage modifyvm "$VM_NAME" --nic1 nat --natpf1 "SSH,tcp,127.0.0.1,1234,10.0.2.15,22"

# Крок 3. Налаштування сховища
# [cite_start]1. Створення контролера SATA (IntelAHCI) [cite: 2303]
VBoxManage storagectl "$VM_NAME" --name "KyrylenkoSATA" --add sata --controller IntelAHCI

# [cite_start]2. Створення контролера IDE (PIIX4) для підключення ISO [cite: 2304]
VBoxManage storagectl "$VM_NAME" --name "KyrylenkoIDE" --add ide --controller PIIX4

# [cite_start]3. Створення віртуального сховища даних (.vdi) [cite: 2305]
VBoxManage createmedium disk --filename DiskKyrylenko.vdi --size $DISK_SIZE --format VDI

# [cite_start]4. Підключення віртуального диску (.vdi) до SATA-контролера [cite: 1472]
VBoxManage storageattach "$VM_NAME" --storagectl "KyrylenkoSATA" --port 0 --device 0 --type hdd --medium DiskKyrylenko.vdi

# [cite_start]5. Підключення ISO-образу до IDE-контролера [cite: 1474]
VBoxManage storageattach "$VM_NAME" --storagectl "KyrylenkoIDE" --port 0 --device 0 --type dvddrive --medium "$ISO_PATH"

# Для запуску скрипта:
# sh CreateVMKyrylenko.sh
