/*
Copyright © 2013 Igor Paliychuk
Copyright © 2013 Kurt Rinnert
Copyright © 2014 Henrik Andersson
Copyright © 2013 Justin Jacobs

This file is part of FLARE.

FLARE is free software: you can redistribute it and/or modify it under the terms
of the GNU General Public License as published by the Free Software Foundation,
either version 3 of the License, or (at your option) any later version.

FLARE is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
FLARE.  If not, see http://www.gnu.org/licenses/
*/

/**
 * class WidgetSlot
 */

#ifndef WIDGET_SLOT_H
#define WIDGET_SLOT_H

#include "CommonIncludes.h"
#include "InputState.h"
#include "Widget.h"
#include "WidgetLabel.h"

class WidgetSlot : public Widget {
private:
	Sprite *slot_selected;
	Sprite *slot_highlight;
	Sprite *slot_disabled;
	Sprite *label_amount_bg;
	Sprite *label_hotkey_bg;

	WidgetLabel label_amount;
	WidgetLabel label_hotkey;
	WidgetLabel label_colorblind_highlight;
	int icon_id;		// current slot id
	int overlay_id;     // icon id for the overlay image
	int amount;			// entries amount in slot
	int max_amount;		// if > 1 always display amount
	std::string amount_str; // formatted display of amount
	int hotkey; // for display in label_hotkey only
	bool activated;

public:
	enum CLICK_TYPE {
		NO_CLICK = 0,
		DRAG = 1,
		ACTIVATE = 2
	};

	enum HIGHLIGHT_TYPE {
		HIGHLIGHT_NORMAL = 0,
		HIGHLIGHT_POWER_MENU,
	};

	static const int NO_ICON = -1;
	static const int NO_OVERLAY = -1;

	explicit WidgetSlot(int _icon_id, int highlight_type);
	~WidgetSlot();

	void setPos(int offset_x, int offset_y);

	void activate();
	void defocus();
	bool getNext();
	bool getPrev();

	CLICK_TYPE checkClick();
	CLICK_TYPE checkClick(int x, int y);
	int getIcon();
	void setIcon(int _icon_id, int _overlay_id);
	void setAmount(int _amount, int _max_amount);
	void setHotkey(int key);
	void render();

	bool enabled;
	bool continuous;	// allow holding key to keep slot activated

	bool visible;

	float cooldown; // normalized
	bool highlight;

	bool show_disabled_overlay;
	bool show_colorblind_highlight;
};

#endif
