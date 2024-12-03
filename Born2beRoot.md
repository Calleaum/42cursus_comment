<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Documentation Système</title>
    <style>
        .title {
            color: red;
            font-weight: bold;
        }
        pre {
            background-color: #f4f4f4;
            padding: 10px;
            border-radius: 5px;
        }
    </style>
</head>
<body>
    <h1 class="title">Partitions :</h1>
    <pre>lsblk</pre>

    <h1 class="title">Secure Shell (SSH) :</h1>
    <p>Protocol de communication sécurisé.</p>

    <h1 class="title">UFW :</h1>
    <p>Uncomplicated Firewal (interface simplifiée pour gérer le firewall).</p>

    <h1 class="title">Apparmor :</h1>
    <p>Module de sécurité de Linux (Chaque processus peut avoir son profil de sécurité).</p>

    <h1 class="title">LVM :</h1>
    <p>Gestionnaire de volume physique.</p>

    <h1 class="title">Cron :</h1>
    <p>Utilitaire pour exécuter des commandes à des moments spécifiques.</p>

    <h2 class="title">Commandes UFW :</h2>
    <pre>
sudo ufw status           # check des ports ouverts ou fermés
sudo ufw allow "XXXX"     # ouvrir un port
sudo ufw delete allow "XXXX"  # fermer un port
    </pre>

    <h2 class="title">Commandes SSH :</h2>
    <pre>
sudo systemctl status ssh       # infos sur SSH
sudo grep Port /etc/ssh/sshd_config  # recherche ligne port dans sshd_config
sudo systemctl restart sshd     # restart ssh pour prendre une nouvelle config
    </pre>

    <h2 class="title">Connexion à distance :</h2>
    <pre>
ssh calleaum42@hostname -I -p 4242
    </pre>

    <h2 class="title">Chemin d'accès :</h2>
    <h3 class="title">Hostname :</h3>
    <pre>
sudo hostnamectl set-hostname new_user   # change hostname
sudo nano /etc/hostname et /etc/hosts    # possibilité de changer manuellement
    </pre>

    <h2 class="title">Monitoring :</h2>
    <pre>
nano /usr/local/bin/monitoring.sh   # modifier script
sh /usr/local/bin/monitoring.sh     # afficher script
sudo crontab -u root -e             # durée de reload script
    </pre>

    <h2 class="title">Groupe :</h2>
    <pre>
sudo adduser "user"         # add user
sudo groupadd "group_name"  # add group
sudo usermod -aG "group" "user"   # add user dans un groupe
sudo deluser "user" "group"      # del un user d'un groupe
getent group "test"         # vérifie les users du groupe
    </pre>

    <h2 class="title">Mot de passe :</h2>
    <pre>
sudo chage -l "user"      # vérifie temps restant mdp
sudo nano /etc/pam.d/common-password    # règles mdp
    </pre>

    <h2 class="title">Sudo :</h2>
    <pre>
dpkg -l | grep sudo            # info version sudo
sudo nano /var/log/sudo/sudo.log    # dossier log sudo
sudo visudo / sudo nano /etc/sudoers  # règles de sécurité sudo
    </pre>
</body>
</html>




