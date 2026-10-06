CMAKE := cmake

PROJECT_DIR := .
BUILD_DIR := ./build
APPDIR := ./AppDir

LINUXDEPLOY := linuxdeploy
LINUXDEPLOY_QT := linuxdeploy-plugin-qt
APPIMAGETOOL := appimagetool

APPIMAGE := ./ResistorGUI-x86_64.AppImage

.PHONY: clean generate build install appimage

clean:
	rm -rf $(BUILD_DIR) $(APPDIR) $(APPIMAGE)

generate:
	$(CMAKE) -S $(PROJECT_DIR) -B $(BUILD_DIR)

build:
	$(CMAKE) --build $(BUILD_DIR) --config Release

install: build
	rm -rf $(APPDIR)
	mkdir -p $(APPDIR)
	$(CMAKE) --install $(BUILD_DIR) --prefix $(APPDIR)/usr

appimage: install
	ARCH=x86_64 $(LINUXDEPLOY) \
		--appdir $(APPDIR) \
		--plugin qt \
		--output appimage