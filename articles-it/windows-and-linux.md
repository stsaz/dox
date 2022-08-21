# Windows and Linux (Fedora KDE): difference, configuration, dual-boot
by Simon Zolin, Dec 2021

I reinstalled both Windows and Linux recently on a notebook PC, and I decided to write the summary article about my experience with both OS.  I'm also going to describe how to configure each OS via command-line and set up a dual-boot system.

*I couldn't place very detailed information about each aspect in this article, so if you think there's something important missing - please send me a message, I'll do my best to update the article.*

Contents:

* [Which OS is better?](#which-os-is-better)
	* [Is it free?](#is-it-free)
	* [Does it spy on you?](#does-it-spy-on-you)
	* [Does it slow down the PC?](#does-it-slow-down-the-pc)
	* [Is auto-update service obtrusive?](#is-auto-update-service-obtrusive)
	* [Does it need Internet connection?](#does-it-need-internet-connection)
	* [Does it have a per-application firewall service?](#does-it-have-a-per-application-firewall-service)
	* [Does the graphics run smoothly?](#does-the-graphics-run-smoothly)
	* [Are there enough configuration options?](#are-there-enough-configuration-options)
	* [What apps are supported?](#what-apps-are-supported)
	* [What games are supported?](#what-games-are-supported)
	* [What hardware sensors are supported?](#what-hardware-sensors-are-supported)
	* [Does it support RAM disks?](#does-it-support-ram-disks)
	* [What's the level of user's freedom?](#whats-the-level-of-users-freedom)
	* [Conclusion](#conclusion)
* [Windows performance configuration via command-line](#windows-performance-configuration-via-command-line)
	* [Disable hibernation](#disable-hibernation)
	* [Disable page file](#disable-page-file)
	* [Disable System Restore](#disable-system-restore)
	* [Disable Auto Update](#disable-auto-update)
	* [Enable Auto Login](#enable-auto-login)
	* [Disable obtrusive scheduled tasks and services](#disable-obtrusive-scheduled-tasks-and-services)
	* [Disable Windows Defender](#disable-windows-defender)
* [Fedora performance configuration via command-line](#fedora-performance-configuration-via-command-line)
	* [Use Intel graphics driver](#use-intel-graphics-driver)
	* [Disable swap](#disable-swap)
	* [Disable SELinux](#disable-selinux)
	* [Disable system logging](#disable-system-logging)
	* [Disable camera](#disable-camera)
	* [Disable bluetooth](#disable-bluetooth)
	* [Disable OOM service](#disable-oom-service)
	* [Disable disk-disturbing services](#disable-disk-disturbing-services)
	* [Remove autostart scripts](#remove-autostart-scripts)
	* [Set up user cache in /tmp](#set-up-user-cache-in-tmp)
	* [Configure KDE environment for max performance](#configure-kde-environment-for-max-performance)
* [Dual-boot: Windows and Fedora on the same disk](#dual-boot-windows-and-fedora-on-the-same-disk)
	* [If you have Windows and want to just TRY Linux](#if-you-have-windows-and-want-to-just-try-linux)
	* [If you have 2 physical disks](#if-you-have-2-physical-disks)
	* [If you want Windows and Linux freshly installed onto one clean disk](#if-you-want-windows-and-linux-freshly-installed-onto-one-clean-disk)
	* [If you have Windows and want to install Linux onto the same disk](#if-you-have-windows-and-want-to-install-linux-onto-the-same-disk)
* [Windows and Linux apps I recommend](#windows-and-linux-apps-i-recommend)


## Which OS is better?

Let's start with a simple question: which OS is better?  The answer is simple: the one that suits your needs the most.  For years my OS of choice was Windows, even though I always liked Linux distributions more, in general.  My problem with them (Linux distributions) was that there's always something that doesn't work out-of-the-box, or in other words, the things that I need don't work because I don't know how to set them up appropriately.  Every problem required investigation and much reading of the forums and FAQs on the Internet in order to fix it.  For example, I experienced issues with my notebook's touchpad, USB mouse, or connecting to VPN, or watching H264 video, or the graphics environment was too slow, or the OS couldn't recognize my phone connected by USB, or something else didn't work.  I wasn't prepared to spend so much time for fixing those things that work on Windows without any problem.  So I used Linux only for programming and for educational purposes.

But thankfully those times are gone now.  **Fedora 35 KDE is my OS of choice**, because there seems to be no hardware issues and all software works quite well as it should after some configuration.  Honestly, it always feels that Linux works a little bit faster than Windows on the same hardware.  Maybe it's because Linux kernel scheduler prioritizes all running processes better and because it smartly caches disk data in memory.  It's very rare that an app is hanging, and even if it's hanging for some reason, it doesn't affect other apps and the graphics environment in general.  In the end, I can always login into the terminal after pressing `Ctrl+Alt+F5` and kill any rogue process with `sudo killall -9 rogue`.  A KDE session can work for weeks without reboot without any freeze (when putting PC to sleep rather than shutting it down).  Windows, on the contrary, sometimes freezes so badly I can't even kill an app after pressing `Ctrl+Alt+Del` and selecting Task Manager option: it doesn't start at all, or it starts but I can't bring it foreground, or I can't switch focus to its window.  I don't see how it's so difficult for Windows to always start Task Manager with the highest process priority and on top of all other windows, but OK.  Thankfully, `Sign Out` option helps most of the time but destroys all unsaved work.

In general, why **I don't like Windows 10** is because I feel so restricted while I'm using it.  There are so many default services that I find obtrusive, and when I try to disable or stop them Windows denies my request and says `Access Denied`.  Obviously, I want to be able to configure my system the way I want but there's just no official way for me to do that.  Windows should just provide enough freedom for their users to be able to disable and delete what they choose to.  But no, there is more and more useless stuff bundled with it every new release.  And there are no means for the users to disable all this useless stuff with a click of a button or a simple command.  It's a shame that many good notebooks come with Windows preinstalled, and the consumers buy Windows, when they could install Linux for free with some help from their friends, for example.  The people have the right to choose their OS themselves, but at the same time they also have the right to want a PC which already has the OS preinstalled, and we can't blame them for that.  To change this behaviour maybe we should start teaching our children in schools how to install Linux OS themselves.  Because if everyone knows how to install an OS, then why would anyone need a notebook with a preinstalled OS?

Another thing worth mentioning about the **Windows preinstalled on a notebook** is that if I try to reformat my disk drive and then install it afresh, then I'd lose my genuine Windows.  So I bought a genuine copy but I can't even reformat my drive?  I can't even reinstall Windows myself?  Windows shouldn't be tied up to SSD, but to the motherboard and CPU, otherwise it's just nonsense to me.  I remember I read some advice long time ago, like "When you buy a notebook with Windows, the first thing you do is format the drive and install a clean Windows yourself".  I absolutely hated the preinstalled Windows version with all that obtrusive crappy apps and services preinstalled.  Nobody with a clear conscience will use a PC with the OS installed by somebody who is not trustworthy.  I tried to reset the OS by clicking the button `Reset to Factory Defaults` I found in Windows settings, but it didn't help: after wasting my time and thrashing my disk Windows reappears to me with the same poor configuration.  I realized that uninstalling all the apps and reconfiguring to a clean installation manually was not possible.  The battle against reality is futile.  So I deleted everything and formatted the disk.  Further in this article I'm describing how to format the disk for dual boot system with Windows and Linux installed together.

Considering my latest experience, I've prepared a short summary table with the things that are different in Windows 10 and Linux (or Fedora 35 KDE specifically).  Note that I use a slash character `/` when an issue can be solved or improved by manual configuration or by installing additional software.

	                        | Windows 10 | Fedora 35 KDE
	------------------------+------------+------------------
	Free?                   | free trial | free
	Spies on you?           | ?/no       | no
	Slows down PC?          | yes/no     | yes/no
	Obtrusive auto-update?  | yes/no     | no
	Needs Internet?         | no         | yes
	App firewall?           | yes        | no
	Graphics runs smoothly? | no/driver  | no/driver+config
	Configuration options?  | basic      | complete
	Supported apps?         | windows    | linux/windows
	Supported games?        | windows    | linux/windows
	Hardware sensors?       | all        | basic
	RAM disk?               | no/app     | yes
	RAM usage?              | medium     | minimal
	User freedom?           | restricted | free

Now let's describe each question in more detail.

### Is it free?

Windows 10 is a shareware product.  It offers a trial period with notifications like `Please Activate Windows`, but the OS doesn't really stop working.

Fedora is a completely free Linux OS.  You don't have to pay to download, to install or use it.  Ever.

### Does it spy on you?

Windows.  I don't know but I surely don't like the possibility of it.  The very first moment I was connected to Internet some services decided to send and receive something from several remote hosts.  No one knows what those services can send to Microsoft or some 3rd party company, until he sits down with a network traffic analyzing software.  Even so, the data is most likely encrypted.  I don't like this situation at all.  Also, the Auto Update service is always online, and who knows what kind of information it really exchanges with the Internet hosts despite receiving the useful payload of binary data meant for updates.

Fedora.  My observation shows that it may request a DNS address for `fedoraproject.org` without my permission.  I didn't analyze which process did it and why, I just blocked this host name and that's all.  I really doubt the OS's default services can send some sensitive info to Fedora developers.  Anyway, we can install a network traffic analyzer (`tcpdump`) and see the current network usage.  And then, it's possible to stop and disable the service which sends something we don't want it to send.

### Does it slow down the PC?

Windows slows down the PC by default services such as Windows Defender, Auto Update, automatic disk drive checks and defragmenting tasks.  Sometimes the CPU usage can reach 100% and disk activity may reach 100% when you are doing nothing.  Thankfully, all these services can be disabled by hard force.

Fedora slows down the PC by default services such as file indexing service, Out-Of-Memory service, RPM repository-related indexing services.  The same as with Windows, CPU and disk usage can reach 100% when there are no user apps running.  But contrary to Windows of course, everything can be disabled quite easily, so there is no problem.  *Note: Intel Graphics users - read on.*

### Is auto-update service obtrusive?

Very much obtrusive Windows Auto Update service can do whatever it wants and when it wants.  For example, I was watching a film and at some point Windows suddenly showed me a topmost blue window with a message `Couldn't Install Updates` covering half of my video screen.  *It ruined the moment.*  It's not a pleasant experience, I must say.

I haven't experienced any problem with Fedora Auto Update service, because I just went on and disabled it the first time I logged into KDE session.  In general, I don't like any automatic update systems, because the OS configuration may change at the moment when I'm not ready for it and without my knowledge in advance about the possibilities of what may go wrong.  Why would I stop my work in the middle and start fixing some new issues I didn't want to occur in the first place?  This is not for me, I don't like any surprises from a machine - I like it working in an explicitly expected way.

### Does it need Internet connection?

Windows works more than fine without Internet connection.  In fact, it works better without Internet ever.  Because the moment you connect Windows to Internet it starts to *crawl like a web spider*.  Windows is better off without Internet - it won't break, it won't annoy you about updates and stuff.  And all Windows applications can be installed without having an Internet connection by executing their installer files from a USB drive for example.

You won't be able to install an app in Fedora without a working Internet connection.  There are no *app installers* in Linux world - there are *app & library packages*.  Developers of Linux distributions in general have a slightly strange point of view about software installer packages.  They think that it's best to have a file repository server somewhere on the Internet that contains all meta information and all binary files for all software built exactly for your OS version.  They think this way it's easier for the users to install apps.  Something like Google Play Store where you go with your Android phone, select an app and install it.  But the problem with Linux packages is that they are not self-contained - they have external *dependencies*.  When we install an app from Google Play Store, the app is packaged by the developers themselves, and the package contains all needed libraries within, and as a result the app will work exactly the way it should - exactly how the developers have tested it prior to releasing it.

However, when we install an app from Fedora repository, we just hope for the best, but we don't know for sure that it will work, because no one has ever tested it thoroughly enough with this particular set of dependency libraries - surely not developers themselves.  On the one hand it's good when we don't trust the app developers and rely on Fedora developers (*In God We Trust*).  But on the other hand, developers don't know exactly which set of libraries their app uses - it makes it harder for them to guarantee that their app will work as expected.  And moreover, *users* are not sure if the app with random dependencies will work correctly and won't contain some security issues, for example.

To give you an idea of what I'm talking about, here's what I've recently experienced with this Linux packaging methodology.  I had a perfectly working ffmpeg package installed.  Then I updated JACK library which was a dependency for JACK development package.  In other words, I installed a JACK development package, which in turn *updated* my existing JACK library, which was a dependency for my ffmpeg package.  This resulted in ffmpeg package stopped working because libjack.so *has changed*.  But I didn't want and I didn't expect this behaviour!  I have never liked this Linux packaging mechanism, but I can live with it since everything is free, and I can change everything by force if I want to.

This approach, however, does have logical reasons behind it.  If a bug is found *inside a library*, Fedora devs can fix *all* their apps by just rebuilding the apps against a newer version of the library which contains the bugfix.  While it can take a couple of hours for them to do so, it may take months before app developers themselves can rebuild their app in this case.  Everything in this world has to have a balance.  There's no single ideal solution to all problems.

To be completely honest, there is a way to install an app on a system without Internet - first you download and copy a bunch of `.rpm` files to a USB flash drive on any system with Internet connection and then unpack (i.e. install) them on a target system.  But this process isn't common, it's not very convenient because you need to copy not just the app package but all of its dependencies too, which in turn have the dependencies of their own.

### Does it have a per-application firewall service?

Windows has a nice firewall app where we can specify the rules of which apps and services are allowed to access which network interfaces.  We can block any app we don't want to access Internet by IP addresses, TCP/UDP ports, network interfaces.  I just wish Windows had a preset option to disable *all* its services from accessing Internet.

Linux doesn't have a per-application firewall.  I really don't know what is the problem behind this, but I hope some day it will be done.

### Does the graphics run smoothly?

Of course the first thing that we do after installing Windows is installing all drivers, especially chipset drivers and graphics drivers.  Without them it's foolish to expect a good graphics performance from the OS.  Installing a driver in Windows is as easy as it can be - just double click on installer file and wait until the installation process finishes.  No configuration is required after, just reboot and we're done.  We can play games and watch video, and desktop environment is fast as lightning.

There's no requirement to install any drivers on Fedora KDE - everything is already installed and preconfigured and works right away.  Or at least it should work.  It's not that straightforward, however, if you have an Intel CPU with integrated graphics.  My i5 8th-gen CPU was running very poorly after installation.  It was easy to come to this conclusion by seeing how windows effects perform, and how hot the CPU was.  I realized that Intel drivers were not used by desktop manager service by default.  I had to enable it by installing some Intel packages and creating a `xorg` configuration file with some specific instructions.  Once I did that, rebooted and then KDE started to work fast like an interstellar spacecraft, except video playback.  I had to add a special option to `mpv` video player configuration file to enable hardware acceleration.  And then all was fine.

### Are there enough configuration options?

Windows.  Not nearly enough.  I can't change graphical environment themes, icon themes, window decorations, and there are only a couple of good looking mouse cursors.  I can't place an analog clock on desktop if I want to.  I can't easily disable some obtrusive default services.  And while I can arrange Start menu icons differently, I can't add Sleep or Shutdown options directly to Start menu.  That's why I got used to pressing `Alt+F4` on desktop and then selecting the option I need in combobox by a letter or arrow keys.

Fedora.  KDE has almost everything that I need and much more.  Everything is customizable, many settings can be changed via command-line or direct editing of a text file which can be easily automated by scripts.  And Control Center app provides a very intuitive interface for global configuration.  Finally, I can easily disable all services that I want to disable, nothing can stop me from doing that.

### What apps are supported?

On Windows we can run only those apps that are built for Windows.  We can run even old executable files (built for Windows XP, for example) on the newest Windows 10 and it will work as expected most of the time.  Otherwise it would be impossible to run old software which may be no longer in development.

On Linux we can run Linux apps natively.  The software for Linux is usually open-source and is usually rebuilt anew each time a new version of Linux distribution is released.  However, in some cases old binary files may also work correctly on the newest Fedora, though this isn't guaranteed by anybody.  On Linux we can also run some Windows apps via the Windows compatibility software called `wine`.  It can even run some 3D games!  Of course, not all apps can run this way, and some apps run but there can be bugs.  Anyway, it still is a very good thing to be able to run Windows software on Linux without any virtual machines.

### What games are supported?

The same sitution is with games.  Windows can run only games for Windows, but Linux can run Linux games, although there are much less games available to play.  Linux OS can also run some Windows games via `wine`, but I don't know about the difference in performance in this case.

### What hardware sensors are supported?

There is a fantastic tool called HWinfo on Windows that can monitor almost all hardware resources in real time.  I recommend it to everyone who tries to understand what's going on with his PC.

On Fedora I can monitor just CPU temperature and a couple of other things, that's all.  Or at least I don't know any app that can provide the level of details like HWinfo has.

### Does it support RAM disks?

Windows doesn't provide functionality for RAM disks out of the box or at least I don't know about this.  But I use an app SoftPerfect RAM Disk and it works just fine.

On Fedora by default we have a `/tmp` directory which stores data in memory.  Additional RAM mount points can be easily created with this command for example:

	sudo mount -t tmpfs -o size=10M tmpfs /mnt/mytmpfs

### How much RAM it uses?

Windows uses about 1.7GB of RAM after boot, which I think is very high, especially after all my configuration.  And I can't even find out which service is using so much memory.  If I remember correctly, Windows XP after some configuration used like 80MB of memory.  Windows 7 uses about 500MB of memory.  So what's up with Windows 10?

Fedora KDE uses about 500MB of memory which is very fine.  There is a huge amount of free memory for the apps and disk cache.

### What's the level of user's freedom?

On Windows user is restricted by almost everything.  It's not even possible to kill some processes that consume resources aggressively.  Administrator rights don't help much, because the system restricts the administrator account too.  So it's quite hard sometimes to disable or delete something in Windows.  Any system service can take the control out from you and you won't be able to do anything, except pressing the Power button.

On Linux user is free to do anything he wants with the system.  You can login as root user and delete everything and it won't even try to stop you from doing that.  That's the kind of power I like when I'm operating a machine.  On Linux you don't do what you don't know, but if you want to do something - just do it.  And knowledge comes with experience.

### Conclusion

Overall, both OS have their advantages and disadvantages.  Everybody should choose what they like more.  The main problem with Windows in my opinion is that it's in control, not me, although for somebody it may be the best option...  The problem with Linux OS, in my case Fedora, is that it's still not user-friendly enough.  There are still some hardware issues out of the box.  Thankfully, almost everything works quite well after configuration.  The one issue I haven't solved so far is that sometimes a pipewire process starts consuming CPU when I'm not listening to any music...  In the end, Fedora can't substitute Windows because some games I sometimes play are Windows-only and some very cool apps are Windows-only.  Linux OS can be a complete alternative to Windows only when game developers start releasing their games for Linux, and when app developers start porting their software to Linux.  But those things need higher demand from the users who prefer Linux.  However, there are still not nearly enough of them.


## Windows performance configuration via command-line

Now let's talk about the configuration process of both OS.  They are not adjusted for performance by default, but for average users.  If you wish to configure your OS so it runs a little faster, my advice may help you a little.  I wish that OS asked what type of user I am while installation process starts.  For power users it's better to switch everything off by default and let them switch on something they need later after installation.  For average users they must at least provide some information about what type of services are active by default so the users at least have some idea about what's running on his system and consuming hardware resources.

Remember that all commands on Windows that change global configuration must be executed inside Console opened as Administrator.  Otherwise, trying to execute such commands in Console opened as normal user will just result in `Access Denied` errors.

Here I describe the most interesting configuration aspects, but not all of them.  See the whole script here: [windows10-post-install.cmd](https://github.com/stsaz/os-post-install/blob/master/windows10-post-install.cmd).

*I have to warn you that you should always understand what you are doing when following some advice like mine below.  Don't trust anybody, check each command before executing, and only if you believe it's safe - do it.  In my case these commands worked, but in other case they may not work for some reason - please keep in mind that.*

*I don't claim ownership to this code - it's based on the advice by Windows community, so thanks to all the people in the world for making this possible.*

### Disable hibernation

Instead of shutting Windows down, we may choose to hibernate instead.  Hibernation is a computer state when it's actually powered off but during the next startup Windows will **resume the session** as it was before.  This process requires that all used memory regions are copied onto SSD.  The more memory computer has, the more data is copied onto SSD, which isn't good for its health.  Personally, I don't need this feature so I disable it by this command:

	powercfg /hibernate off

### Disable page file

Page file - additional memory stored actually on SSD - is needed when the PC is nearly out of free memory.  In this case Windows will push some inactive memory regions onto SSD, thus freeing some RAM for the app which currently needs it desperately.  But my notebook has 8GB of RAM and it's more than enough for everything I run on my PC, even 3D games, so why would I need a page file?  Remember that page file is needed only in case there is a program that needs more memory than PC actually has.  This is the command that disables and deletes page file:

	wmic computersystem where name="%computername%" set AutomaticManagedPagefile=False
	wmic pagefileset where name="C:\\pagefile.sys" delete

### Disable System Restore

System Restore is a standard service enabled by default which tries to protect your data from corruption.  But if you really love your sensitive data, you should copy it onto an external disk which is usually disconnected from your PC.  Then your data is at least 99% safe there.  Relying on some blackbox services such as System Restore is pointless in my opinion.  On the other hand, if you always install and uninstall some new software and playing with Windows configuration, then it may be smart to leave SR enabled so it can help you with recovering the previous Windows state.

This code disables System Restore service completely:

	echo "delete all restore points"
	vssadmin delete shadows /for=c: /all /quiet

	powershell -Command "& {Disable-ComputerRestore -Drive C:\}"

	echo "disable system restore task"
	schtasks /change /TN "Microsoft\Windows\SystemRestore\SR" /disable >nul

	echo "disable service: Microsoft Software Shadow Copy Provider"
	sc config swprv start=disabled

	echo "disable service: Volume Shadow Copy"
	sc config VSS start=disabled

### Disable Auto Update

Generally it's not safe to disable Auto Update service because your Windows will be outdated and vulnerable to security issues.  On the other hand, AU can break the perfectly working system at any time.  But nevertheless it's user's choice.  As for me, I like my OS exactly the way I installed it and without *any* other further reconfiguration, I like to keep such things static - that's what I expect from a machine.

As you can see, disabling AU services isn't that simple.  It's not enough just to disable the services, because they will be turned back on by periodic tasks (Task Scheduler subsystem).  So we need to disable those too, but we can't because if we try, we'll get `Access Denied` error.  So we must first provide full access for ourselves - we have to change file permissions.  And then we can disable periodic tasks, but it seems some tasks can be disabled only via Power Shell command.

	echo "disable service: WindowsUpdate"
	sc config wuauserv start=disabled

	echo "disable service: UpdateOrchestrator"
	sc config UsoSvc start=disabled

	echo "take ownership for the dir"
	takeown /a /r /f c:\Windows\System32\Tasks\Microsoft\Windows\UpdateOrchestrator

	echo "grant full access file permissions to administrators"
	icacls c:\Windows\System32\Tasks\Microsoft\Windows\UpdateOrchestrator /t /grant administrators:f

	echo "disable tasks"
	schtasks /change /TN "Microsoft\Windows\WindowsUpdate\Scheduled Start" /disable >nul
	powershell -Command "& {Disable-ScheduledTask -TaskName 'Microsoft\Windows\UpdateOrchestrator\Schedule Scan' }"
	powershell -Command "& {Disable-ScheduledTask -TaskName 'Microsoft\Windows\UpdateOrchestrator\USO_UxBroker' }"
	powershell -Command "& {Disable-ScheduledTask -TaskName 'Microsoft\Windows\UpdateOrchestrator\Report Policies' }"

### Enable Auto Login

One useful thing when there's just one person who uses the computer is when OS automatically signs me in without prompting for password.  However, I don't know how to do it completely from command-line.  `netplwiz` command just brings up a window where you should uncheck a checkbox manually.  But in order for it to work, we first need to update Windows Registry.

	echo "enable auto login without password prompt"
	reg add "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\PasswordLess\Device" /v "DevicePasswordLessBuildVersion" /t REG_DWORD /d 0 /f >nul

	echo "In this window uncheck `Users Must Enter A User Name And Password To Use This Computer`"
	netplwiz

### Disable obtrusive scheduled tasks and services

I don't like when something starts using my CPU and "spinning my disks" without my permission or even when the computer is idle.  Here's the code that disables everything I find obtrusive - automatic disk checkers, defragmentors, analyzers, synchonization tasks, etc.  However, I don't know how to add firewall rule via command-line, so you have to do it manually.

For a long time already I've been trying to understand one thing: how can developers write software that use CPU while in idle state, .e.g. when the window is minimized and the app has no active jobs?  If the window is minimized then there's no graphics redrawing, and if there's nothing active - no need to use CPU, right?  Well, just look at how many apps actually use a small amount of CPU time while they shouldn't.  That's why I try to use my own software for long running tasks such as audio playback, because my `fmedia` player consumes very little CPU when I listen to music and it doesn't consume any CPU when in idle state - when the music is stopped - because there's literally nothing for it to do in this case!  I wish every developer knew how to use hardware resources minimally, but there are too many people who don't care at all...

Anyway, here we disable periodic tasks and the services.

	echo "disable obtrusive scheduled tasks and services"
	schtasks /change /TN "Microsoft\Windows\Autochk\Proxy" /disable >nul
	schtasks /change /TN "Microsoft\Windows\DiskDiagnostic\Microsoft-Windows-DiskDiagnosticDataCollector" /disable >nul
	schtasks /change /TN "Microsoft\Windows\Feedback\Siuf\DmClient" /disable >nul
	schtasks /change /TN "Microsoft\Windows\Windows Error Reporting\QueueReporting" /disable >nul
	schtasks /change /TN "Microsoft\Windows\Chkdsk\ProactiveScan" /disable >nul
	schtasks /change /TN "Microsoft\Windows\Defrag\ScheduledDefrag" /disable >nul
	schtasks /change /TN "Microsoft\Windows\DiskCleanup\SilentCleanup" /disable >nul
	schtasks /change /TN "Microsoft\Windows\Maintenance\WinSAT" /disable >nul
	schtasks /change /TN "Microsoft\Windows\Registry\RegIdleBackup" /disable >nul
	schtasks /change /TN "Microsoft\Windows\Time Synchronization\SynchronizeTime" /disable >nul
	schtasks /change /TN "Microsoft\Windows\Time Zone\SynchronizeTimeZone" /disable >nul

	echo "disable Microsoft Account Sign-in Assistant"
	sc config wlidsvc start=disabled

	echo "disable Background Intelligent Transfer Service"
	sc config BITS start=disabled

	echo "disable Microsoft Account Sign-in Assistant"
	sc config wlidsvc start=disabled

	echo "disable Microsoft Windows SMS Router Service"
	sc config SmsRouter start=disabled

	echo "disable Cryptographic Services"
	sc config CryptSvc start=disabled

	echo "disable Microsoft Store Install Service"
	sc config InstallService start=disabled

And now manually add outbound firewall rules to block:

* `C:\Windows\ImmersiveControlPanel\SystemSettings.exe`
* `C:\Windows\SystemApps\Microsoft.Windows.Search_XXX\searchapp.exe`

### Disable Windows Defender

I'm grateful to Microsoft that they are trying to protect somehow their users from catching viruses and stuff, but is that *really their concern*?  I always thought that the purpose of OS is to give users the ability to operate with their hardware and to provide necessary means for other software to run.  The purpose of OS shouldn't be to protect users from something, therefore any "realtime protection" services should only be activated by user's choice.  And what if I don't want to be "protected" at all?  It turns out there's no simple solution on how to disable this "protection".

> The only real protection the people should have is their consciousness, the people should be smart enough to stop trusting everyone around and start thinking with their own brains.  And then our world will be much better as the people won't do anything stupid by trusting someone they don't know with "protecting them" from the unknown bad thing which will never in fact happen or which may not even exist.  In other words, if you don't really know what you are trying to protect yourself from, are you sure you need this kind of protection?

Back to OS configuration.  First, you should disable Tamper Protection setting manually, otherwise the code below won't work.

1. Press Windows key to open Start Menu
2. Enter "tamper" and press Enter
3. Set Tamper Protection = Off

Then this code should be able to disable the realtime protection, remove system tray icon, remove context menu options and finally disable the services and periodic tasks:

	reg add "HKEY_LOCAL_MACHINE\Software\Policies\Microsoft\Windows Defender" /v "DisableAntiVirus" /t REG_DWORD /d "1" /f >nul
	reg add "HKEY_LOCAL_MACHINE\Software\Policies\Microsoft\Windows Defender\MpEngine" /v "MpEnablePus" /t REG_DWORD /d "0" /f >nul
	reg add "HKEY_LOCAL_MACHINE\Software\Policies\Microsoft\Windows Defender\Real-Time Protection" /v "DisableBehaviorMonitoring" /t REG_DWORD /d "1" /f >nul
	reg add "HKEY_LOCAL_MACHINE\Software\Policies\Microsoft\Windows Defender\Real-Time Protection" /v "DisableIOAVProtection" /t REG_DWORD /d "1" /f >nul
	reg add "HKEY_LOCAL_MACHINE\Software\Policies\Microsoft\Windows Defender\Real-Time Protection" /v "DisableOnAccessProtection" /t REG_DWORD /d "1" /f >nul
	reg add "HKEY_LOCAL_MACHINE\Software\Policies\Microsoft\Windows Defender\Real-Time Protection" /v "DisableRealtimeMonitoring" /t REG_DWORD /d "1" /f >nul
	reg add "HKEY_LOCAL_MACHINE\Software\Policies\Microsoft\Windows Defender\Real-Time Protection" /v "DisableRoutinelyTakingAction" /t REG_DWORD /d "1" /f >nul
	reg add "HKEY_LOCAL_MACHINE\Software\Policies\Microsoft\Windows Defender\Real-Time Protection" /v "DisableScanOnRealtimeEnable" /t REG_DWORD /d "1" /f >nul
	reg add "HKEY_LOCAL_MACHINE\Software\Policies\Microsoft\Windows Defender\Reporting" /v "DisableEnhancedNotifications" /t REG_DWORD /d "1" /f >nul
	reg add "HKEY_LOCAL_MACHINE\Software\Policies\Microsoft\Windows Defender\SpyNet" /v "DisableBlockAtFirstSeen" /t REG_DWORD /d "1" /f >nul
	reg add "HKEY_LOCAL_MACHINE\Software\Policies\Microsoft\Windows Defender\SpyNet" /v "SpynetReporting" /t REG_DWORD /d "0" /f >nul
	reg add "HKEY_LOCAL_MACHINE\Software\Policies\Microsoft\Windows Defender\SpyNet" /v "SubmitSamplesConsent" /t REG_DWORD /d "2" /f >nul
	reg add "HKEY_LOCAL_MACHINE\System\CurrentControlSet\Control\WMI\Autologger\DefenderApiLogger" /v "Start" /t REG_DWORD /d "0" /f >nul
	reg add "HKEY_LOCAL_MACHINE\System\CurrentControlSet\Control\WMI\Autologger\DefenderAuditLogger" /v "Start" /t REG_DWORD /d "0" /f >nul

	echo "disable systray icon"
	reg delete "HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Explorer\StartupApproved\Run" /v "SecurityHealth" /f >nul
	reg delete "HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Run" /v "SecurityHealth" /f >nul

	echo "remove context menu"
	reg delete "HKEY_CLASSES_ROOT\*\shellex\ContextMenuHandlers\EPP" /f >nul
	reg delete "HKEY_CLASSES_ROOT\Directory\shellex\ContextMenuHandlers\EPP" /f >nul
	reg delete "HKEY_CLASSES_ROOT\Drive\shellex\ContextMenuHandlers\EPP" /f >nul

	rem sc config doesn't work here
	reg add "HKEY_LOCAL_MACHINE\System\CurrentControlSet\Services\WdFilter" /v "Start" /t REG_DWORD /d "4" /f >nul
	reg add "HKEY_LOCAL_MACHINE\System\CurrentControlSet\Services\WdNisDrv" /v "Start" /t REG_DWORD /d "4" /f >nul
	reg add "HKEY_LOCAL_MACHINE\System\CurrentControlSet\Services\WdNisSvc" /v "Start" /t REG_DWORD /d "4" /f >nul
	reg add "HKEY_LOCAL_MACHINE\System\CurrentControlSet\Services\WinDefend" /v "Start" /t REG_DWORD /d "4" /f >nul
	reg add "HKEY_LOCAL_MACHINE\System\CurrentControlSet\Services\SecurityHealthService" /v "Start" /t REG_DWORD /d "4" /f >nul

	schtasks /change /TN "Microsoft\Windows\ExploitGuard\ExploitGuard MDM policy Refresh" /disable
	schtasks /change /TN "Microsoft\Windows\Windows Defender\Windows Defender Cache Maintenance" /disable
	schtasks /change /TN "Microsoft\Windows\Windows Defender\Windows Defender Cleanup" /disable
	schtasks /change /TN "Microsoft\Windows\Windows Defender\Windows Defender Scheduled Scan" /disable
	schtasks /change /TN "Microsoft\Windows\Windows Defender\Windows Defender Verification" /disable

Note that `sc config` command may not work here to disable the services, so we do it by updating the Registry.  Microsoft provides the utility to operate with Windows services and it sometimes just doesn't work, how crazy is that?


## Fedora performance configuration via command-line

Fedora needs much post-install configuration too, but it's much more simple, everything here is clear and should work without problems.

Here I describe the most interesting configuration aspects, but not all of them.  See the whole script here: [fedora-post-install.sh](https://github.com/stsaz/os-post-install/blob/master/fedora-post-install.sh).

*I don't claim ownership to this code - it's based on the advice by Linux community, so thanks to all the people in the world for making this possible.*

### Use Intel graphics driver

For Intel users with integrated graphics such as myself it's absolutely crucial to install the graphics driver appropriately.  Without it the CPU usage is much higher than it should be and the CPU is hotter.

What the code below does is:

1. Install RPMFusion repository which contains the Intel drivers we need.
2. Download and installs Intel drivers and utilities.
3. Create a new configuration file for X window manager.  Note that these settings may not work correctly on your particular system - in this case you should find the working configuration by yourself.

The changes will take effect after reboot.  Remember that if after reboot you can't login to KDE, it's a normal result of misconfiguration.  It's easy to fix this: just login into terminal and edit the file via `nano` or simply delete it with `rm`.

```
sudo dnf install -y https://download1.rpmfusion.org/free/fedora/rpmfusion-free-release-$(rpm -E %fedora).noarch.rpm

echo "install driver, vainfo, intel_gpu_top"
sudo dnf install -y libva-intel-driver libva-intel-hybrid-driver intel-mediasdk intel-gmmlib libva-utils igt-gpu-tools

sudo echo 'Section "Module"
Load "dri3"
EndSection

Section "Device"
Identifier "Intel"
Driver "intel"
Option "AccelMethod" "sna"
Option "DRI" "3"
Option "TripleBuffer" "true"
Option "TearFree" "true"
EndSection' >/etc/X11/xorg.conf.d/20-intel.conf
```

### Disable swap

Swap on Linux is the same as page file on Windows.  See my explanation of what page file is in section `Disable page file`.

	sudo swapoff -a
	sudo dnf erase -y zram-generator

### Disable SELinux

SELinux is some Linux kernel protection module which sometimes prevents me from doing the things I want, so I just disable it.

	echo "add kernel option to /boot/loader/entries/*"
	sudo grubby --update-kernel ALL --args selinux=0

### Disable system logging

During the time when Fedora is running, it keeps writing some data onto disk in `/var/log` directory.  That info may be useful when you're trying to debug some problems with your OS.  Normally, it's not needed and it can be disabled to preserve the health of SSD and to slightly speed up the system in general.

This code disables `rsyslog` service completely and then tells the systemd logger not to write any data to disk.

	sudo systemctl disable rsyslog

	sudo sed -i 's/#Storage=auto/Storage=none/' /etc/systemd/journald.conf
	sudo sed -i 's/#SystemMaxUse=/SystemMaxUse=0/' /etc/systemd/journald.conf
	systemctl daemon-reload

### Disable camera

Disabling the camera is useful when you don't need it.  Even when some messaging software will try to access it, they won't be able to do so.

	sudo echo "blacklist uvcvideo" >>/etc/modprobe.d/blacklist.conf

### Disable bluetooth

Here we disable bluetooth service and disable all bluetooth kernel modules.

	sudo systemctl disable bluetooth
	sudo echo "blacklist bluetooth
	blacklist btusb
	blacklist btrtl
	blacklist btbcm
	blacklist btintel" >>/etc/modprobe.d/blacklist.conf

### Disable OOM service

I saw how systemd OOM service was using my CPU aggressively, so I had to disable it.  But notice that we don't disable it with usual `systemctl disable` - it won't work.

	sudo systemctl mask systemd-oomd

### Disable disk-disturbing services

These services were using my disk aggressively, so here's how I disabled them:

	sudo balooctl disable
	sudo systemctl disable dnf-makecache.service
	sudo systemctl disable dnf-makecache.timer

### Remove autostart scripts

These are the scripts that automatically start on KDE login.  I don't see why I need them, so I just removed them.  This code first makes a backup archive with all these files and then deletes them.

	echo "backup autostart scripts to ~/xdg-autostart-backup.tgz and then delete them"
	AUTOSTART_FILES="baloo_file.desktop \
	geoclue-demo-agent.desktop \
	gnome-keyring-pkcs11.desktop \
	gnome-keyring-secrets.desktop \
	gnome-keyring-ssh.desktop \
	kaccess.desktop \
	klipper.desktop \
	liveinst-setup.desktop \
	org.kde.discover.notifier.desktop \
	pam_kwallet_init.desktop \
	polkit-kde-authentication-agent-1.desktop \
	spice-vdagent.desktop \
	tracker-miner-fs-3.desktop \
	tracker-miner-rss-3.desktop \
	vmware-user.desktop \
	xembedsniproxy.desktop"
	tar -C /etc/xdg/autostart -czf ~/xdg-autostart-backup.tgz $AUTOSTART_FILES
	cd /etc/xdg/autostart && sudo rm -vf $AUTOSTART_FILES && cd -

### Set up user cache in /tmp

My favorite configuration trick that prolongs the life of my SSD is to move cache directory to a temporary storage in `/tmp`.  The most obvious reason for this is that browser cache will no longer be stored on disk but in memory until you reboot.  Here's what we need to do:

1. First we create a script file that prepares the cache directory inside `/tmp`.
2. Then we create a systemd service file that will be executed on after system boot.  The service just executes our script file.
3. Then we execute our script immediately and make a symbolic link to the new cache directory.

Here's the code:

```
USER_ID=`id -u`
echo "create user script"
echo "mkdir -p /tmp/u${USER_ID}_cache
chown ${USER_ID}:${USER_ID} /tmp/u${USER_ID}_cache" >~/bin/init_user_cache.sh

echo "create and enable systemd service"
sudo echo "[Unit]
Description=Create user cache directory
DefaultDependencies=false
After=network.target

[Service]
Type=simple
ExecStart=/usr/bin/sh $HOME/bin/init_user_cache.sh

[Install]
WantedBy=multi-user.target" >/usr/lib/systemd/system/user_init_cache.service

sudo systemctl enable user_init_cache

sh ~/bin/init_user_cache.sh
rm -rf ~/.cache
ln -s /tmp/u${USER_ID}_cache ~/.cache
```

### Configure KDE environment for max performance

This code disables KWallet, disables file preview in Doplhin, simplifies `Ctrl+Tab` screen, disables all animations.

	kwriteconfig5 --file breezerc --group 'Common' --key 'ShadowSize' 'ShadowNone'
	kwriteconfig5 --file breezerc --group 'Windeco' --key 'DrawBackgroundGradient' 'false'
	kwriteconfig5 --file ksplashrc --group 'KSplash' --key 'Engine' 'none'
	kwriteconfig5 --file ksplashrc --group 'KSplash' --key 'Theme' 'None'
	kwriteconfig5 --file kwalletrc --group 'Wallet' --key 'Enabled' 'false'
	kwriteconfig5 --file kwinrc --group 'TabBox' --key 'HighlightWindows' 'false'
	kwriteconfig5 --file kwinrc --group 'TabBox' --key 'LayoutName' 'big_icons'
	kwriteconfig5 --file dolphinrc --group 'PreviewSettings' --key 'Plugins' ''

	echo "disable all animations"
	kwriteconfig5 --file breezerc --group 'Style' --key 'AnimationsEnabled' 'false'
	kwriteconfig5 --file breezerc --group 'Windeco' --key 'AnimationsEnabled' 'false'
	kwriteconfig5 --file kwinrc --group 'Plugins' --key 'blurEnabled' 'false'
	kwriteconfig5 --file kwinrc --group 'Plugins' --key 'contrastEnabled' 'false'
	kwriteconfig5 --file kwinrc --group 'Plugins' --key 'desktopgridEnabled' 'false'
	kwriteconfig5 --file kwinrc --group 'Plugins' --key 'kwin4_effect_dialogparentEnabled' 'false'
	kwriteconfig5 --file kwinrc --group 'Plugins' --key 'kwin4_effect_fadeEnabled' 'false'
	kwriteconfig5 --file kwinrc --group 'Plugins' --key 'kwin4_effect_fadingpopupsEnabled' 'false'
	kwriteconfig5 --file kwinrc --group 'Plugins' --key 'kwin4_effect_frozenappEnabled' 'false'
	kwriteconfig5 --file kwinrc --group 'Plugins' --key 'kwin4_effect_fullscreenEnabled' 'false'
	kwriteconfig5 --file kwinrc --group 'Plugins' --key 'kwin4_effect_loginEnabled' 'false'
	kwriteconfig5 --file kwinrc --group 'Plugins' --key 'kwin4_effect_logoutEnabled' 'false'
	kwriteconfig5 --file kwinrc --group 'Plugins' --key 'kwin4_effect_maximizeEnabled' 'false'
	kwriteconfig5 --file kwinrc --group 'Plugins' --key 'kwin4_effect_morphingpopupsEnabled' 'false'
	kwriteconfig5 --file kwinrc --group 'Plugins' --key 'kwin4_effect_squashEnabled' 'false'
	kwriteconfig5 --file kwinrc --group 'Plugins' --key 'kwin4_effect_translucencyEnabled' 'false'
	kwriteconfig5 --file kwinrc --group 'Plugins' --key 'kwin4_effect_windowapertureEnabled' 'false'
	kwriteconfig5 --file kwinrc --group 'Plugins' --key 'presentwindowsEnabled' 'false'
	kwriteconfig5 --file kwinrc --group 'Plugins' --key 'screenedgeEnabled' 'false'
	kwriteconfig5 --file kwinrc --group 'Plugins' --key 'slideEnabled' 'false'
	kwriteconfig5 --file kwinrc --group 'Plugins' --key 'slidingpopupsEnabled' 'false'
	kwriteconfig5 --file kwinrc --group 'Plugins' --key 'zoomEnabled' 'false'


## Dual-boot: Windows and Fedora on the same disk

No matter what type of OS you like more, it doesn't hurt to try something new sometimes.  If you normally use Windows, you may want to try Fedora.  Or if you use Linux OS, you may need Windows for some good Windows-only apps or games.  I use dual-boot PC configuration all the time and I may switch OS whenever I want, it takes less than 30 seconds.  The one and only thing user must understand is how to prepare the disk to support both OS.  There are several options, let's discuss them one by one.

### If you have Windows and want to just TRY Linux

...Then you don't even need to install anything.  You just:

1. Download any Live CD with Linux OS such as Fedora KDE Live.
2. Copy  contentthes from the downloaded `.iso` file with `rufus` app onto a USB drive.
3. Then reboot Windows and keep pressing `Esc` or `F12` key (depends on your BIOS settings) during boot to bring up the menu where you can select `Start Fedora`.
4. After Fedora is loaded you can do whatever you want with it - it won't change your data on disk without your permission, so it's safe.

Note that if you have an Intel GPU you may experience poor graphics performance - I don't know if it's really possible to use Intel graphics driver as I describe in this article with Live Fedora.

### If you have 2 physical disks

...Then it should be easy: no matter what OS you have installed first, you just need to install the second OS onto your second disk.

### If you want Windows and Linux freshly installed onto one clean disk

...Which is the option I use myself and the only option suitable for nearly all notebook users.  Once we have a clean disk, or a disk with the data we don't care about, we may begin.

But first we need to decide how we're going to split our disk for Windows and Linux.  The safest way is to split 50-50%.  But if you want to play games on Windows and use Linux just for Internet browsing, you may split 80-20% Windows-way.  It's always your decision, but it will be much harder to change it once we install the OSes.

Secondly, we need to decide whether we want to have separate system partitions and data partitions or we want just to use the available space entirely.  The advantage of the first method is that we can easily reinstall OS in the future without even touching our data partitions.  The advantage of the second method is that all available disk space is used more effectively when we don't know in advance how much space we need for the system partition.

I almost forgot, we also need a clean USB drive.

#### Installing Windows first

1. With the working Windows we download the official Windows 10 image from Microsoft.
2. Download `rufus` free app.
3. Insert a USB drive, start `rufus`, select your USB drive, select Windows 10 `.iso` file we've just downloaded, start copying files.  This will take some time.
4. Reboot.  Most likely the Windows installation will start automatically.  But if not, keep pressing `Esc` or `F12` key (depends on your BIOS settings) during boot to bring up the boot menu where you can select your USB Windows installation drive.
5. When Windows disk partitioning screen comes up, delete all existing partitions, if any, until there's only 1 row left - `Unallocated space`.  Now create a system partition with at least 20GB.  If you need a separate partition for data, create it too.  Just leave enough unallocated space for Linux.
6. Click on the first partition row so it becomes highlighted then proceed with installing Windows.

P.S. After Windows is installed, in case our disk is partitioned as MBR (which is unlikely though) we may need to convert it to a new GPT partition scheme with these commands:

	mbr2gpt /validate /allowFullOS
	mbr2gpt /convert /allowFullOS

The same can be done before installing Windows, but I don't have the exact steps for you on how to do it.

#### Installing Fedora next to Windows

Now is the time to install Fedora.

1. Download Fedora KDE Live image.
2. Download `rufus` free app.
3. Copy Fedora installer onto USB drive with `rufus`.
4. Reboot, select `Start Fedora` option in boot menu.
5. After Fedora has booted, click on `Install to disk` icon to start the installation.
6. Inside the disk partitioning screen choose Manual partitioning.  Leave all Windows partitions untouched and create new partitions from the free unallocated space.  For example, we create a Linux boot partition of 100MB size mounted to `/boot/efi`.  Then we create a system partition with `/` mount point with all the rest of available disk space.  Optionally, we can create a data partition with `/home` mount point.  If you need a swap partition, create it too.
7. Fedora will automatically install its boot loader and add a Windows option there so we can choose what OS we want to load on each boot.

P.S. In case after reboot you are still booted into Windows, you need to change your BIOS settings.  Enter BIOS setup, find Boot Entries list, move the Fedora entries up to the top or add them yourself if necessary.

### If you have Windows and want to install Linux onto the same disk

Fedora needs some space on your disk where it will be installed.  You'll need at least 10GB of free space.  If you don't have any free space left on your disk, you should free it first:

* If you have `C:` and `D:` drives, you may free some space using standard utilities: open `Computer Management` -> `Disk Manager`, select your `D:` drive and do a `Shrink` on it.  If it doesn't work, try defragmenting the partition or better move all your data to an external disk, because I'm not sure that it won't destroy your data.

* If you have only `C:` drive, it's harder to free the space from the system partition - you need to use some advanced software which I know nothing about.

* In any case I guess it's possible to free some space from your disk using the Linux tools (such as `gparted` or `KDE Partition Manager`) from Live Linux CD, but you absolutely should move your data to an external disk before trying to do that.

Once you have an unallocated space on your disk, you may proceed with installing Linux as I described above.


## Windows and Linux apps I recommend

Finally, here's the list of the apps that I use myself and I recommend everyone else to use them.

	                 | Linux            | Windows
	-----------------+------------------+--------------------
	File manager     | krusader,        | total commander
	                 | double commander |
	Text editor      | kate             | notepad++
	Code editor      | sublime-text,    | sublime-text,
	                 | vscode           | vscode
	Browser          | firefox          | firefox
	Dictionary       | goldendict       | goldendict
	Graphics         | gwenview         | irfanview,
	                 |                  | fast stone image viewer
	Video player     | mpv              | vlc
	Audio player     | fmedia           | fmedia
	Sound studio     | reaper           | reaper
	CPU temp monitor | lm_sensors       | hwinfo
	RAM disk         | (not needed)     | softperfect ram disk

Some notes:

* I use mainly Krusader as a file manager, but sometimes it's not enough and I need to use Double Commander.  On Windows Total Commander does everything that I need, but Double Commander won't hurt either.  The problem with the latter is that I find it using my CPU much more aggressively than Krusader, though sometimes it's much more convenient as it resembles Total Commander closer.

* I use mainly Sublime Text but also use VSCode when necessary.  VSCode consumes more CPU resources, it's obvious for me that Sublime Text is faster in every way.

* GoldenDict is a nice software that supports different dictionary data formats.  It's free, cross-platform, portable and open-source.

* mpv is a very fast video player which supports almost all video formats.  But for some reason it doesn't use Intel GPU hardware acceleration by default, so it must be configured first.

* fmedia is my software that I recommend to anyone who isn't obsessed with pretty graphics.  It's simple, free, cross-platform, portable and open-source.  It suits my needs well and keeps CPU, memory and disk usage at the absolute minimum.

* reaper is a sound studio app I discovered for myself quite recently.  It absolutely blew my mind with its native Linux/ALSA support.  The developers are going in the right direction with their product.

* Though I placed lm_sensors and HWinfo app in the same line, they are completely different things.  lm_sensors, or rather `sensors`, is a small program that shows the current CPU temperature.  HWinfo is a complete full-featured app to monitor all hardware and its temperature, voltage, resource usage and everything else.

* RAM disk is something that Windows desperately needs to have by default, in my opinion.  *It needs RAM disk much more than some "defenders".*  But SoftPerfect RAM Disk works fine without any problem and many thanks to SoftPerfect for that.

Note: on Windows it's always a good practice to block Internet access to the apps via Firewall to prevent the possibility for them sending your private data to unknown remote servers.  Open-source software usually doesn't do that, but who knows for sure what other software can do?


## Conclusion

That's all I have to say about Windows and Fedora.  Everyone has the right to choose what he likes more.  Linux and Fedora are still developing in the right direction, while Windows is going the wrong way, in my opinion.  If this trend continues, Linux will have even more desktop users which will result in even better quality of Linux applications.  Free or open-source software is better in many ways.  The problem is just that some very good developers still don't want to invest into Linux world for some reason.  But once it happens, there will be no reason to use Windows anymore, unless Microsoft starts addressing the issues such as those we talked about here.

Anyway, it doesn't matter which OS we use and which applications we like, but what really matters is that we should always think with our head before doing anything.  We may choose the software that needs less energy power, or we may spin our hardware at 300W power level for 24/7 and we may not care at all...  But we all live in the same environment which is planet Earth.  So let us at least try to think about the possible results of our own doings, try to foresee the implications of our deeds.  Because in the end, the computers, or any technology, or the money, or any stuff in general - all this isn't our ultimate purpose on this world, but the life is.  And our own health, and the health of the next generation, and the life of our planet - these are the main things we should care about.
