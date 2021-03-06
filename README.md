## About

**xcproj** is a command line tool for manipulating Xcode project files. It doesn’t do much yet. It also serves as a testbed for [XCDUndocumentedChecker](https://github.com/0xced/xcproj/blob/develop/Sources/XCDUndocumentedChecker.m).

## Installation

### Homebrew

```
brew install xcproj
```

### Manually

To install the `xcproj` tool in `/usr/local/bin` run the following command, with `sudo` if required:

```
xcodebuild -scheme xcproj install DSTROOT=/
```

If you want to install `xcproj` in a custom location, e.g. `~/bin`, run the following command:

```
xcodebuild -scheme xcproj install DSTROOT=/ INSTALL_PATH=~/bin
```

## Usage

```
xcproj [options] <action> [arguments]

Options:
 -h, --help        Show this help text and exit
 -V, --version     Show program version and exit
 -p, --project     Path to an Xcode project (*.xcodeproj file). If not specified, the project in the current working directory is used 
 -t, --target      Name of the target. If not specified, the first target is used

Actions:
 * list-targets
     List all the targets in the project

 * list-headers [All|Public|Project|Private] (default=Public)
     List headers from the `Copy Headers` build phase

 * read-build-setting <build_setting>
     Evaluate a build setting and print its value. If the build setting does not exist, nothing is printed

 * write-build-setting <build_setting> <value>
     Assign a value to a build setting. If the build setting does not exist, it is added to the target

 * add-xcconfig <xcconfig_path>
     Add an xcconfig file to the project and base all configurations on it

 * add-resources-bundle <bundle_path>
     Add a bundle to the project and in the `Copy Bundle Resources` build phase

 * touch
     Rewrite the project file
```

## Limitations

* **xcproj** relies on the DevToolsCore private framework. Although great care has been taken, it might stop working when you upgrade Xcode.

* The **xcproj** binary is bound to the Xcode version that compiled it. If you delete, move or rename the Xcode version that compiled the binary, **xcproj** will fail with the following error and explicit recovery suggestion:
* 
```
DVTFoundation.framework not found. It probably means that you have deleted, moved or renamed the Xcode copy that compiled `xcproj`.
Simply recompiling `xcproj` should fix this problem.
```

* When transitioning from Xcode 4 to Xcode 5, you will get this error:
*  
```
The DVTFoundation framework failed to load: Error Domain=NSCocoaErrorDomain Code=3586 "The bundle “DVTFoundation” couldn’t be loaded because it isn’t compatible with the current application." (dlopen_preflight(/Applications/Xcode.app/Contents/SharedFrameworks/DVTFoundation.framework/DVTFoundation): no suitable image found.  Did find:
	/Applications/Xcode.app/Contents/SharedFrameworks/DVTFoundation.framework/DVTFoundation: GC capability mismatch) UserInfo=0x40032bda0 {NSLocalizedFailureReason=The bundle isn’t compatible with this application., NSLocalizedRecoverySuggestion=Try installing a newer version of the bundle., NSFilePath=/Applications/Xcode.app/Contents/SharedFrameworks/DVTFoundation.framework/DVTFoundation, NSDebugDescription=dlopen_preflight(/Applications/Xcode.app/Contents/SharedFrameworks/DVTFoundation.framework/DVTFoundation): no suitable image found.  Did find:
	/Applications/Xcode.app/Contents/SharedFrameworks/DVTFoundation.framework/DVTFoundation: GC capability mismatch, NSBundlePath=/Applications/Xcode.app/Contents/SharedFrameworks/DVTFoundation.framework, NSLocalizedDescription=The bundle “DVTFoundation” couldn’t be loaded because it isn’t compatible with the current application.}
```
This is because Xcode 4 requires garbage collection and Xcode 5 is built with ARC. Again, to fix this problem, just recompile **xcproj**.  
Note that if Xcode 4 and Xcode 5 are installed at different paths, **xcproj** will work fine.

## Contact

Cédric Luthi

- http://github.com/0xced
- http://twitter.com/0xced
- cedric.luthi@gmail.com
