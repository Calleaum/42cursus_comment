Partitions = lsblk 

Secure Shell (SSH) = Protocol de com securise
UFW = Uncomplicated Firewal (interface simplifiee pour gere le firewall)
Apparmor = Module de securite de Linux (Chaque processus peut avoir son profil de secu)
lvm = Gestionnaire de volume physique
Cron utilitaire pour executer des commandes dans des temps specifique 

		Partitions :
lsblk

		Commandes UFW :
sudo ufw status	
check des ports ouvert ou ferme

sudo ufw allow "XXXX"			
ouvrir un port

sudo ufw delete allow "XXXX"
fermer un port

		Commandes SSH :
sudo systemctl status ssh		
infos sur SSH

sudo grep Port /etc/ssh/sshd_config	
recherche Ligne port dans sshd_config

sudo systemctl restart sshd            
Restart ssh pour prendre une nouvelle config

		Connection distance:
ssh calleaum42@ hostname -I -p 4242

		Chemin acces :	
		Hostname :
sudo hostnamectl set-hostname new_user	
change hostname

sudo nano /etc/hostname  et /etc/hosts	
Possibilite de changer manuellement
		
		Monitoring :
nano /usr/local/bin/monitoring.sh 	
modifier script

sh   /usr/local/bin/monitoring.sh 	
afficher script

sudo crontab -u root -e 		
Duree de reload script



		Groupe :
sudo adduser "user"			
add user

sudo groupadd "group_name"		
add group

sudo usermod -aG "group" "user"		
add user dans un groupe

sudo deluser "user" "group"		
del un user d'un groupe

getent group "test"			
verif les user du groupe


		mot de passe :
sudo chage -l "user"			
verif temps restant mdp

sudo nano /etc/pam.d/common-password	
regles mdp

		sudo :
dpkg -l | grep sudo			
info version sudo

sudo nano /var/log/sudo/sudo.log	
dossier log sudo

sudo visudo / sudo nano /etc/sudoers	
regles secu sudo




