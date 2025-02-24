/*************************************************************************/
/*  editor_network_profiler.h                                            */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2022 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2022 Godot Engine contributors (cf. AUTHORS.md).   */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#ifndef EDITOR_NETWORK_PROFILER_H
#define EDITOR_NETWORK_PROFILER_H

#include "scene/debugger/scene_debugger.h"
#include "scene/gui/box_container.h"
#include "scene/gui/button.h"
#include "scene/gui/label.h"
#include "scene/gui/split_container.h"
#include "scene/gui/tree.h"

#include "../multiplayer_debugger.h"

class EditorNetworkProfiler : public VBoxContainer {
	GDCLASS(EditorNetworkProfiler, VBoxContainer)

private:
	using RPCNodeInfo = MultiplayerDebugger::RPCNodeInfo;

	Button *activate = nullptr;
	Button *clear_button = nullptr;
	Tree *counters_display = nullptr;
	LineEdit *incoming_bandwidth_text = nullptr;
	LineEdit *outgoing_bandwidth_text = nullptr;

	Timer *frame_delay = nullptr;

	HashMap<ObjectID, RPCNodeInfo> nodes_data;

	void _update_frame();

	void _activate_pressed();
	void _clear_pressed();

protected:
	void _notification(int p_what);
	static void _bind_methods();

public:
	void add_node_frame_data(RPCNodeInfo p_frame);
	void set_bandwidth(int p_incoming, int p_outgoing);
	bool is_profiling();

	EditorNetworkProfiler();
};

#endif // EDITOR_NETWORK_PROFILER_H
