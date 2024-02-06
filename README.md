# Real-time Flood Surveillance and Early Warning System using IoT- AI Fusion for Flood Prediction: Smart Framework to Monitoring Solutions

## About this project

This project aims to lessen the damage and casualties for upcoming calamities such as floods with the help of the Internet of Things(IOT) and Artificial Intelligence(AI) for the people in low-level areas in Valenzuela Brgy in Metro Manila, Philippines.

<table style="text-align: center;">
 <thead>
   <tr>
     <th></th>
     <th>Project Manager</th>
     <th>Web Dev</th>
     <th>UI/UX Designer</th>
     <th>AI Dev</th>
     <th>IoT Dev</th>
     <th>QA</th>
     <th>Documentation</th>
   </tr>
   <tr>
      <td>Team Leader</td>
      <td colspan="7">Andrew Jules R. Miyajima</td>
    </tr>
 </thead>
  <tbody>
    <tr>
      <td>Head</td>
      <td>Jonh Ronel M. Zuñiga</td>
      <td>Lloyd Sydlik Nim</td>
      <td>John Joseph M. Cuenco</td>
      <td>Prince Angelico A. Ebora</td>
      <td>Jemar M. Laborte</td>
      <td>John A. Garcia</td>
      <td>Miguel Angel P. Bautista</td>
    </tr>
    <tr>
      <td rowspan="5">Members</td>
      <td>Myro Sebastien M. Mera</td>
      <td>Jonh Ronel M. Zuñiga</td>
      <td>Niño B. Garcia</td>
      <td>Miguel Angel P. Bautista</td>
      <td colspan="3">Andrew Jules R. Miyajima</td>
    </tr>
    <tr>
      <td></td>
      <td>Myro Sebastien M. Mera</td>
      <td></td>
      <td></td>
      <td></td>
      <td>Jemar M. Laborte</td>
      <td>John A. Garcia</td>
    </tr>
    <tr>
      <td></td>
      <td>Mark Angelo A. Balino</td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
    <tr>
      <td></td>
      <td>Andrew D. Robin </td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
    <tr>
      <td></td>
      <td>Paul Benedict M. Santos</td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
    
  </tbody>
</table>

## Project setup and installation

### Forking the repository

- **Forking** means creating a copy of the repository to your own github account. This forked copy will hold all the proposed (pushed) updates that you want to contribute to the project. The update will then be pushed to the original repository after a successful approval.

#### Steps

1. Go to this [github link](https://github.com/RikuRedfox/IOT_AI_MONITOR) to go our repository.
2. Look of the the `Fork` button (usually located at the top-right corner, next to the repository title).
3. Name it anything you like (Usually dont change it so that you can remember it more effectively).
4. Make sure you check the `Copy the main branch only` checkbox and click the `Make Fork` button.

### Pulling the remote repository contents to your local repository

- This time, were going to **clone** the forked repository to our local machine(your computer).

#### Steps

1. Copy the https/SSH link of the repository you forked.
2. Create a folder inside your Windows Explorer (somewhere you will remember).
3. Inside the Folder you created, Shift + Right Click then click the `Open in Powershell` button.
4. Once opened, type `git clone` then paste the https code you copied the in the github page.
5. Once done, type `git init` to initilize the repository.

### Installing and running the backend (laravel) development server

- Before anything, make sure you have PHP installed and put PHP path to your System Variable path. If not, [Click this link](https://www.apachefriends.org/download.html) and download the latest and greatest version.

#### Steps

1. [Click this link](https://getcomposer.org/download/) and click the `Composer-Setup.exe` link to download composer.
2. Once done, go to your VSCode Workspace where you forked your repository and open the terminal. Make sure your'e in the laravel folder. If not and your'e already in the terminal, use `cd laravel` to direct you to that folder.
3. Once your'e in the terminal, type `composer install` and wait until it is finished.
4. To run a local laravel server, type `php artisan serve` and wait until it gives you a URL. Once done, Copy the URL and paste it on your browser.

### Installing and running the backend (ReactJS) development server

- Before anything, make you have nodeJS installed on your computer. If not, [Click this link](https://nodejs.org/en) and download the Long Term Support(LTS) version. Once downloaded, just click "next" until it is finally installed.

1. Go to your VSCode Workspace where you forked your repository and open the terminal. Make sure your'e in the frontend folder. If not and your'e already in the terminal, use `cd frontend` to direct you to that folder.
2. Once in the terminal, type `npm install` to install the dependencies.
3. To run the local react server, type `npm run dev` and wait until it gives you the local URL. Once finished, Copy the URL and paste it on the browser.

### Procedures on how to add, commit, and push your changes to your forked repository

1. if your'e already inside VScode, you can use the terminal to proceed.

   - if you want to do it in powershell, go to the folder of the forked repository and **Shift + Right Click** the folder then click the `Open in PowerShell` button.

2. once opened, type `git add [File name or path/ "." for all files]` to add it to git. Once you added the files, you can type `git status` to check your added files.
3. once done, type `git commit -m "[short description of your changes]"` to save your changes to git. ("-m" means the message command in git). Make sure that the message is in string type.
4. once you commit your changes, type `git push -u origin main` to send it to your github(Note: git and github are different).
