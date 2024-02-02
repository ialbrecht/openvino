// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "op/squeeze.hpp"

#include "openvino/op/constant.hpp"
#include "openvino/op/squeeze.hpp"

using namespace ov::op;

OPENVINO_SUPPRESS_DEPRECATED_START
namespace ngraph {
namespace onnx_import {
namespace op {
namespace set_1 {
ov::OutputVector squeeze(const Node& node) {
    auto data = node.get_ng_inputs().at(0);
    const auto axes = node.get_attribute_value<std::vector<std::int64_t>>("axes", {});

    if (axes.empty()) {
        return {std::make_shared<v0::Squeeze>(data)};
    } else {
        const auto axes_const = std::make_shared<v0::Constant>(ov::element::i64, ov::Shape{axes.size()}, axes);
        return {std::make_shared<v0::Squeeze>(data, axes_const)};
    }
}

}  // namespace set_1

namespace set_13 {
ov::OutputVector squeeze(const Node& node) {
    const auto inputs = node.get_ng_inputs();
    if (inputs.size() < 2) {
        return {std::make_shared<v0::Squeeze>(inputs.at(0))};
    } else {
        return {std::make_shared<v0::Squeeze>(inputs.at(0), inputs.at(1))};
    }
}

}  // namespace set_13
}  // namespace op
}  // namespace onnx_import
}  // namespace ngraph
OPENVINO_SUPPRESS_DEPRECATED_END
