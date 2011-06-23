<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function worx_blog_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => 1);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function worx_blog_imagecache_default_presets() {
  $items = array(
    'worx_blog_be_scale_100w' => array(
      'presetname' => 'worx_blog_be_scale_100w',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '100',
            'height' => '',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    'worx_blog_be_scale_200w' => array(
      'presetname' => 'worx_blog_be_scale_200w',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '200',
            'height' => '',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    'worx_blog_be_thumb_45w_45h' => array(
      'presetname' => 'worx_blog_be_thumb_45w_45h',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_resize',
          'data' => array(
            'width' => '45',
            'height' => '45',
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function worx_blog_views_api() {
  return array(
    'api' => '2',
  );
}
