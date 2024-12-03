:bulb:Secure Shell (SSH)  
Protocol de com securise  

:bulb:UFW = Uncomplicated Firewal  
(interface simplifiee pour gere le firewall)  

:bulb:Apparmor = Module de securite de Linux  
(Chaque processus peut avoir son profil de secu)  

:bulb:lvm = Gestionnaire de volume physique  

:bulb:Cron utilitaire pour executer des commandes dans des temps specifique   

		Partitions
:bulb:lsblk

		Commandes UFW
:bulb:sudo ufw status  
check des ports ouvert ou ferme

:bulb:sudo ufw allow "XXXX"  			
ouvrir un port

:bulb:sudo ufw delete allow "XXXX"  
fermer un port

		Commandes SSH
:bulb:sudo systemctl status ssh  
infos sur SSH  

:bulb:sudo grep Port /etc/ssh/sshd_config	  
recherche Ligne port dans sshd_config  

:bulb:sudo systemctl restart sshd              
Restart ssh pour prendre une nouvelle config  

		Connection distance
:bulb:ssh calleaum42@ hostname -I -p 4242  

		Hostname
:bulb:sudo hostnamectl set-hostname new_user  
change hostname  

:bulb:sudo nano /etc/hostname  et /etc/hosts  
Possibilite de changer manuellement  
		
		Monitoring
:bulb:nano /usr/local/bin/monitoring.sh  
modifier script  

:bulb:sh   /usr/local/bin/monitoring.sh  
afficher script  

:bulb:sudo crontab -u root -e  
Duree de reload script  



		Groupe
:bulb:sudo adduser "user"  
add user  

:bulb:sudo groupadd "group_name"  
add group  

:bulb:sudo usermod -aG "group" "user"  
add user dans un groupe  

:bulb:sudo deluser "user" "group"  		
del un user d'un groupe  

:bulb:getent group "test"  
verif les user du groupe  


		mot de passe
:bulb:sudo chage -l "user"  
verif temps restant mdp  

:bulb:sudo nano /etc/pam.d/common-password  
regles mdp  

		sudo
:bulb:dpkg -l | grep sudo  
info version sudo  

:bulb:sudo nano /var/log/sudo/sudo.log  
dossier log sudo  

:bulb:sudo visudo / sudo nano /etc/sudoers  
regles secu sudo  




