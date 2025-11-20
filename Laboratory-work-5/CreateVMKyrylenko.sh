VBoxManage modifyvm "Linux of Kyrylenko 2" --memory 2458

VBoxManage modifyvm "Linux of Kyrylenko 2" --cpus 1

VBoxManage modifyvm "Linux of Kyrylenko 2" --nic1 nat --natpf1 "SSH,tcp,127.0.0.1,1234,10.0.2.15,22"

VBoxManage storagectl "Linux of Kyrylenko 2" --name "KyrylenkoSATA" --add sata --controller IntelAHCI

VBoxManage storagectl "Linux of Kyrylenko 2" --name "KyrylenkoIDE" --add ide --controller PIIX4

VBoxManage createmedium disk --filename DiskKyrylenko.vdi --size 9800 --format VDI

VBoxManage storageattach "Linux of Kyrylenko 2" --storagectl "KyrylenkoSATA" --port 0 --device 0 --type hdd --medium DiskKyrylenko.vdi

VBoxManage storageattach "Linux of Kyrylenko 2" --storagectl "KyrylenkoIDE" --port 0 --device 0 --type dvddrive --medium "C:/Users/.../ubuntu-14.04.6-server-amd64.iso"


