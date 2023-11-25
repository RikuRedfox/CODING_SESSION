#!/bin/bash

# To execute bash script
# chmod +x filename.sh
# function to clean up unnecessary packages
update_package() {
  sudo apt update
}

clean_up() {
  sudo apt autoremove
}

# Update the system
sudo apt update && sudo apt upgrade -y

# Install net tools
sudo apt install -y net-tools

clean_up

# Install latest Java
sudo apt install default-jdk

# Install build-essential(GCC and G++)
sudo apt install build-essential

# Install Pyhton 3
sudo apt install python3

# Install Dart
sudo apt install dart

# Install Prerequisites
sudo apt install software-properties-common apt-transport-https wget gpg
# Import Microsoft’s GPG Key
wget -qO- https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor >packages.microsoft.gpg
sudo install -D -o root -g root -m 644 packages.microsoft.gpg /etc/apt/keyrings/packages.microsoft.gpg
# Add Microsoft’s Visual Studio Code Repository
sudo sh -c 'echo "deb [arch=amd64,arm64,armhf signed-by=/etc/apt/keyrings/packages.microsoft.gpg] https://packages.microsoft.com/repos/code stable main" > /etc/apt/sources.list.d/vscode.list'
# Update the Package Cache
update_package
# Install Visual Studio Code
sudo apt install code

# Install Microsoft Edge
sudo apt install dirmngr ca-certificates software-properties-common apt-transport-https curl -y
echo 'deb [arch=amd64 signed-by=/usr/share/keyrings/microsoft-edge.gpg] https://packages.microsoft.com/repos/edge stable main' | sudo tee /etc/apt/sources.list.d/microsoft-edge.list
sudo apt install microsoft-edge-stable

# Install Krita
sudo flatpak remote-add --if-not-exists flathub https://flathub.org/repo/flathub.flatpakrepo
flatpak install flathub org.kde.krita -y

# Install Kdenlive
sudo add-apt-repository ppa:kdenlive/kdenlive-stable
update_package
sudo apt install kdenlive

# Install OBS
sudo apt install obs-studio

# Install Handbrake
sudo flatpak install flathub fr.handbrake.ghb -y

# Install MPV
sudo apt install mpv

# Install Discord
wget "https://discord.com/api/download?platform=linux&format=deb" -O discord.deb
sudo apt install ./discord.deb

# Install GNS3
sudo apt install gns3

# Add cloudflare gpg key
curl -fsSL https://pkg.cloudflareclient.com/pubkey.gpg | sudo gpg --yes --dearmor --output /usr/share/keyrings/cloudflare-warp-archive-keyring.gpg
# Add this repo to your apt repositories
echo "deb [arch=amd64 signed-by=/usr/share/keyrings/cloudflare-warp-archive-keyring.gpg] https://pkg.cloudflareclient.com/ $(lsb_release -cs) main" | sudo tee /etc/apt/sources.list.d/cloudflare-client.list
# Install CloudFare 1.1.1.1
sudo apt-get update && sudo apt-get install cloudflare-warp

# Install Wine
sudo dpkg --add-architecture i386
sudo mkdir -pm755 /etc/apt/keyrings
sudo wget -O /etc/apt/keyrings/winehq-archive.key https://dl.winehq.org/wine-builds/winehq.key
sudo wget -NP /etc/apt/sources.list.d/ https://dl.winehq.org/wine-builds/ubuntu/dists/jammy/winehq-jammy.sources
update_package
sudo apt install --install-recommends winehq-stable -yy

#Install Lutris
sudo add-apt-repository ppa:lutris-team/lutris
sudo apt-get update
sudo apt-get install lutris

# Install Steam
sudo apt install steam

#Install Heroic Game Launcher
git clone https://github.com/redromnon/HeroicBashLauncher.git
cd HeroicBashLauncher
chmod +x HeroicBashLauncher

clean_up
