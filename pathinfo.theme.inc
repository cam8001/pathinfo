<?php
/**
 * @file
 * Contains theme implementations for pathinfo.module.
 */

/**
 * Returns a div with a simple string describing the current path.
 *
 * @param array $variables
 *   An associative array containing:
 *   - path: System path to url.
 *   - function: The function that serves the path.
 *   - arguments: Any arguments passed to the function that serves the path.
 *   - module: The module that contains the function.
 *   - implemented_in: The file that contains the function.
 *   - line: The line the function is implemented on.
 *
 * @ingroup themeable
 */
function theme_pathinfo_served_by($variables) {
  // Convert variable names to t() arguments.
  $t_arguments = array(
    '@path' => $variables['path'],
    '@function' => $variables['function'],
    '@arguments' => $variables['arguments'],
    '@module' => $variables['module'],
    '@implemented_in' => $variables['implemented_in'],
    '@line' => $variables['line'],
  );
  $message = '@path is served by @function';
  if ($is_form) {
    $message .= ' (form definition)';
  }
  $message .= ', implemented by @module in @implemented_in at line with arguments: @arguments';

  $message = t_safe($message, $t_arguments);
  $output = '<div class="pathinfo pathinfo-served-by">';
  $output .= $message;
  $output .= '</div>';

  return $output;
}
