<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function worx_blog_ctools_plugin_api() {
  module_load_include('inc', 'worx_blog', 'worx_blog.defaults');
  $args = func_get_args();
  return call_user_func_array('_worx_blog_ctools_plugin_api', $args);
}

/**
 * Implementation of hook_default_page_manager_pages().
 */
function worx_blog_default_page_manager_pages() {
  module_load_include('inc', 'worx_blog', 'worx_blog.defaults');
  $args = func_get_args();
  return call_user_func_array('_worx_blog_default_page_manager_pages', $args);
}

/**
 * Implementation of hook_user_default_permissions().
 */
function worx_blog_user_default_permissions() {
  module_load_include('inc', 'worx_blog', 'worx_blog.defaults');
  $args = func_get_args();
  return call_user_func_array('_worx_blog_user_default_permissions', $args);
}

/**
 * Implementation of hook_strongarm().
 */
function worx_blog_strongarm() {
  module_load_include('inc', 'worx_blog', 'worx_blog.defaults');
  $args = func_get_args();
  return call_user_func_array('_worx_blog_strongarm', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function worx_blog_views_default_views() {
  module_load_include('inc', 'worx_blog', 'worx_blog.features.views');
  $args = func_get_args();
  return call_user_func_array('_worx_blog_views_default_views', $args);
}
